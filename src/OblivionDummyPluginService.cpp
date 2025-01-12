#include "OblivionDummyPluginService.h"

namespace BsaPacker
{
	OblivionDummyPluginService::OblivionDummyPluginService(
		const IFileWriterService* fileWriterService,
		const IDummyPluginLogic* dummyPluginLogic)
		: m_FileWriterService(fileWriterService),
		m_DummyPluginLogic(dummyPluginLogic)
	{
	}

	bool BsaPacker::OblivionDummyPluginService::CreatePlugin(const QString& modPath,
		const QString& archiveNameBase) const
	{
		const QString& fileNameNoExtension = modPath + '/' + archiveNameBase;
		if (!this->m_DummyPluginLogic->canCreateDummyESP(fileNameNoExtension, libbsarchpp::ArchiveType::TES4))
		{
			return false;
		}
		const std::string& absoluteFileName = fileNameNoExtension.toStdString() + ".esp";
		return this->m_FileWriterService->Write(absoluteFileName,
			reinterpret_cast<const char*>(OblivionDummyPluginService::RAW_OBLIVION),
			sizeof(OblivionDummyPluginService::RAW_OBLIVION));
	}
}

