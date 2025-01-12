#ifndef ARCHIVEBUILDERFACTORY_H
#define ARCHIVEBUILDERFACTORY_H

#include "bsapacker_global.h"
#include <bsapacker/IArchiveBuilderFactory.h>
#include <bsapacker/IArchiveBuilder.h>
#include <bsapacker/IArchiveBuilderHelper.h>
#include <bsapacker/IModDto.h>
#include <libbsarchppWrapper.h>

namespace BsaPacker
{
	class BSAPACKER_EXPORT ArchiveBuilderFactory : public IArchiveBuilderFactory
	{
	public:
		ArchiveBuilderFactory(const IArchiveBuilderHelper* archiveBuilderHelper);
		~ArchiveBuilderFactory() override = default;
		ArchiveBuilderFactory(const ArchiveBuilderFactory&) = delete;
		ArchiveBuilderFactory& operator=(const ArchiveBuilderFactory&) = delete;
		ArchiveBuilderFactory(ArchiveBuilderFactory&&) = delete;
		ArchiveBuilderFactory& operator=(ArchiveBuilderFactory&&) = delete;

		[[nodiscard]] std::vector<libbsarchpp::ArchiveType> GetArchiveTypes(const IModDto* modDto) const override;
		[[nodiscard]] std::unique_ptr<IArchiveBuilder> Create(libbsarchpp::ArchiveType archiveType, const IModDto* modDto) const override;

	private:
		const IArchiveBuilderHelper* m_ArchiveBuilderHelper = nullptr;
	};
} // namespace BsaPacker

#endif // ARCHIVEBUILDERFACTORY_H
