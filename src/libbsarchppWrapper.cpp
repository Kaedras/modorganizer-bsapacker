#include "libbsarchppWrapper.h"

#include <libbsarchpp/Bsa.h>

using namespace std;

namespace libbsarch
{
    libbsarchppWrapper::libbsarchppWrapper(libbsarchpp::ArchiveType type): m_archiveType(type)
    {
    }

    void libbsarchppWrapper::add_file_from_disk(const std::filesystem::path& path_in_archive,
                                                const std::filesystem::path& absolute_path)
    {
        files_.emplace_back(disk_blob(path_in_archive, absolute_path));
    }

    void libbsarchppWrapper::add_file_from_disk(const disk_blob& blob)
    {
        files_.emplace_back(blob);
    }

    void libbsarchppWrapper::add_files_from_disk(const std::vector<disk_blob>& blobs)
    {
        files_.reserve(blobs.size());
        files_.insert(files_.end(), blobs.cbegin(), blobs.cend());
    }

    void libbsarchppWrapper::add_file_from_memory(const std::filesystem::path& path_in_archive,
                                                  const std::vector<char>& data)
    {
        files_.emplace_back(path_in_archive, data);
    }

    void libbsarchppWrapper::add_file(const bs_packed_file& file)
    {
        files_.emplace_back(file);
    }

    void libbsarchppWrapper::set_compressed(bool value)
    {
        m_compressed = value;
    }

    void libbsarchppWrapper::set_dds_base_path(const std::filesystem::path& dds_base_path)
    {
        m_archive->setDDSBasePath(dds_base_path);
    }

    void libbsarchppWrapper::set_share_data(bool value)
    {
        m_shareData = value;
    }

    void libbsarchppWrapper::extract_all(const std::filesystem::path& directory, bool overwrite_current_files)
    {
        namespace fs = std::filesystem;
        for (const auto& file : m_archive->getFileList())
        {
            fs::path path_string = directory / file;
            fs::path current_path = path_string.remove_filename();

            create_directories(current_path);
            if (exists(path_string) && overwrite_current_files)
            {
                fs::remove(path_string);
                m_archive->extractFile(file, path_string);
            }
            else if (!exists(path_string))
                m_archive->extractFile(file, path_string);
        }
    }

    void libbsarchppWrapper::load_from_disk(const std::filesystem::path& archive_path)
    {
        m_archive = make_unique<libbsarchpp::Bsa>(archive_path);
        for (const auto& file : m_archive->getFileList())
        {
            entries_.emplace_back(file);
        }
    }

    void libbsarchppWrapper::save_to_disk(const std::filesystem::path& archive_path)
    {
        for (const auto& file : files_)
        {
            entries_.emplace_back(file.path_in_archive);
        }

        libbsarchpp::Bsa bsa(archive_path, m_archiveType, entries_);
        bsa.setCompressed(m_compressed);
        bsa.setShareData(m_shareData);

        for (const auto& file : files_)
        {
            switch (file.data.index())
            {
            case 0:
                {
                    const auto& blob = std::get<std::vector<char>>(file.data);
                    add_file_from_memory(file.path_in_archive, blob);
                    break;
                }
            case 1:
                {
                    const auto& file_path = std::get<std::string>(file.data);
                    add_file_from_disk(file.path_in_archive, file_path);
                }
            }
        }
        bsa.save();
    }
}
