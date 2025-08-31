#include "ArchiveNameService.h"

#include "NexusId.h"

#include <QFileInfo>

namespace BsaPacker
{
	ArchiveNameService::ArchiveNameService(const IModContext* modContext)
		: m_ModContext(modContext)
	{
	}

	QString ArchiveNameService::GetFileExtension() const
	{
		switch (this->m_ModContext->GetNexusId()) {
		case NexusId::Morrowind:
		case NexusId::Oblivion:
		case NexusId::Fallout3:
		case NexusId::NewVegas:
		case NexusId::Skyrim:
		case NexusId::SkyrimSE:
		case NexusId::Enderal:
		case NexusId::EnderalSE:
			return QStringLiteral(".bsa");
		case NexusId::Fallout4:
		case  NexusId::Starfield:
			return QStringLiteral(".ba2");
		default:
			return QString();
		}
	}

	QString ArchiveNameService::GetArchiveFullPath(const libbsarchpp::ArchiveType type, const IModDto* modDto) const
	{
		const QString& pathNoExt(QDir::toNativeSeparators(modDto->Directory() + '/' + modDto->ArchiveName() + this->Infix(type)));
		const QString& suffix = this->Suffix(pathNoExt);
		return QDir::toNativeSeparators(pathNoExt + suffix + this->GetFileExtension());
	}

	QString ArchiveNameService::Infix(const libbsarchpp::ArchiveType type) const
	{
		switch (type) {
		case libbsarchpp::FO4:
		case libbsarchpp::SF:
			return QStringLiteral(" - Main");
		case libbsarchpp::SFdds:
		case libbsarchpp::FO4dds:
			return QStringLiteral(" - Textures");
		case libbsarchpp::TES3:
		case libbsarchpp::TES4:
		case libbsarchpp::FO3:
		case libbsarchpp::SSE:
		case libbsarchpp::none:
		default:
			return QString();
		};
	}

	// gets the number to append when there are multiple archives
	// a way to avoid overwriting any existing files
	QString ArchiveNameService::Suffix(const QString& pathNoExt) const {
		int archiveIndex = 0;
		const QString& fileExt = this->GetFileExtension();
		QFileInfo fileInfo(pathNoExt + fileExt);
		while (fileInfo.exists()) {
			++archiveIndex;
			fileInfo.setFile(pathNoExt + QString::number(archiveIndex) + fileExt);
		}
		if (archiveIndex != 0) {
			return QString::number(archiveIndex);
		}
		return QString();
	}
}
