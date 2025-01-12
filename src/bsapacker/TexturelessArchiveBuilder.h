#ifndef TEXTURELESSARCHIVEBUILDER_H
#define TEXTURELESSARCHIVEBUILDER_H

#include "bsapacker_global.h"
#include <bsapacker/IArchiveBuilder.h>
#include <bsapacker/IArchiveBuilderHelper.h>
#include <QDir>

namespace BsaPacker
{
	class BSAPACKER_EXPORT TexturelessArchiveBuilder : public IArchiveBuilder
	{
		Q_OBJECT
			Q_INTERFACES(BsaPacker::IEmitsValueChanged)

	public:
		TexturelessArchiveBuilder(const IArchiveBuilderHelper* archiveBuilderHelper, const QDir& rootDir, const libbsarchpp::ArchiveType& type);
		~TexturelessArchiveBuilder() override = default;

		uint32_t setFiles() override;
		void setShareData(bool) override;
		[[nodiscard]] std::vector<std::unique_ptr<libbsarch::libbsarchppWrapper>> getArchives() override;
		[[nodiscard]] uint32_t getFileCount() const override;
		[[nodiscard]] QString getRootPath() const override;

	public Q_SLOTS:
		void cancel() override;

	private:
		const IArchiveBuilderHelper* m_ArchiveBuilderHelper = nullptr;
		std::vector<std::unique_ptr<libbsarch::libbsarchppWrapper>> m_Archives;
		const libbsarchpp::ArchiveType m_ArchiveType;
		bool m_Cancelled;
		QDir m_RootDirectory;
		const static qint64 SIZE_LIMIT;
	};
} // namespace BsaPacker

#endif // TEXTURELESSARCHIVEBUILDER_H
