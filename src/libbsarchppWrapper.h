#ifndef LIBBSARCHPPWRAPPER_H
#define LIBBSARCHPPWRAPPER_H

#include <filesystem>
#include <vector>
#include <variant>
#include <libbsarchpp/Bsa.h>
#include <libbsarchpp/enums.h>

namespace libbsarch
{
    struct disk_blob
    {
        disk_blob(const std::filesystem::path& root_dir, const std::filesystem::path& absolute_path)
            : path_in_archive(absolute_path)
              , path_on_disk(absolute_path)
        {
            path_in_archive = relative(path_in_archive, root_dir);
        }

        disk_blob(const std::filesystem::path& path_in_archive,
                  const std::filesystem::path& absolute_path,
                  [[maybe_unused]] bool decoy_parameter)
            : path_in_archive(path_in_archive)
              , path_on_disk(absolute_path)
        {
        }

        std::filesystem::path path_in_archive;
        std::filesystem::path path_on_disk;
    };

    struct bs_packed_file
    {
        bs_packed_file(const disk_blob& blob)
            : path_in_archive(blob.path_in_archive)
              , data(blob.path_on_disk)
        {
        }

        bs_packed_file(std::filesystem::path path_in_archive, std::vector<char> blob)
            : path_in_archive(std::move(path_in_archive))
              , data(blob)
        {
        }

        std::filesystem::path path_in_archive;
        std::variant<std::vector<char>, std::string> data;
    };

    class libbsarchppWrapper
    {
    public:
        libbsarchppWrapper() = delete;
        libbsarchppWrapper(libbsarchpp::ArchiveType type);

        void add_file_from_disk(const std::filesystem::path& path_in_archive,
                                const std::filesystem::path& absolute_path);
        void add_file_from_disk(const disk_blob& blob);
        void add_files_from_disk(const std::vector<disk_blob>& blobs);
        void add_file_from_memory(const std::filesystem::path& path_in_archive, const std::vector<char>& data);
        void add_file(const bs_packed_file& file);

        void set_compressed(bool value);
        void set_dds_base_path(const std::filesystem::path& dds_base_path);
        void set_share_data(bool value);

        void extract_all(const std::filesystem::path& directory, bool overwrite_current_files);

        void load_from_disk(const std::filesystem::path& archive_path);
        void save_to_disk(const std::filesystem::path& archive_path);

    private:
        std::vector<bs_packed_file> files_;
        std::vector<std::filesystem::path> entries_;
        std::unique_ptr<libbsarchpp::Bsa> m_archive = nullptr;
        libbsarchpp::ArchiveType m_archiveType;
    };
}
#endif // LIBBSARCHPPWRAPPER_H
