#ifndef IARCHIVEBUILDERFACTORY_H
#define IARCHIVEBUILDERFACTORY_H

#include <bsapacker/IModDto.h>
#include <bsapacker/IArchiveBuilder.h>

namespace BsaPacker
{
	class IArchiveBuilderFactory
	{
	public:
		virtual ~IArchiveBuilderFactory() = default;
		virtual std::vector<libbsarchpp::ArchiveType> GetArchiveTypes(const IModDto* modDto) const = 0;
		virtual std::unique_ptr<IArchiveBuilder> Create(libbsarchpp::ArchiveType archiveType, const IModDto* modDto) const = 0;
	};
}

#endif // IARCHIVEBUILDERFACTORY_H
