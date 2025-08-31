#include <bsapacker/ArchiveBuilderFactory.h>

#include <bsapacker/GeneralArchiveBuilder.h>
#include <bsapacker/NullArchiveBuilder.h>
#include <bsapacker/TextureArchiveBuilder.h>
#include <bsapacker/TexturelessArchiveBuilder.h>
#include "NexusId.h"

using namespace libbsarchpp;

namespace BsaPacker
{
	ArchiveBuilderFactory::ArchiveBuilderFactory(const IArchiveBuilderHelper* archiveBuilderHelper)
		: m_ArchiveBuilderHelper(archiveBuilderHelper)
	{
	}

	std::vector<libbsarchpp::ArchiveType> ArchiveBuilderFactory::GetArchiveTypes(const IModDto* modDto) const
	{
		switch (modDto->NexusId()) {
			case NexusId::Morrowind:
				return std::vector<libbsarchpp::ArchiveType> { TES3 };
			case NexusId::Oblivion:
				return std::vector<libbsarchpp::ArchiveType> { TES4 };
			case NexusId::Fallout3:
			case NexusId::NewVegas:
			case NexusId::Skyrim:
			case NexusId::Enderal:
				return std::vector<libbsarchpp::ArchiveType> { FO3 };
			case NexusId::SkyrimSE:
			case NexusId::EnderalSE:
				return std::vector<libbsarchpp::ArchiveType> { SSE };
			case NexusId::Fallout4:
				return std::vector<libbsarchpp::ArchiveType> { FO4, FO4dds };
			case NexusId::Starfield:
				return std::vector<libbsarchpp::ArchiveType> { SF, SFdds };
			default:
				return std::vector<libbsarchpp::ArchiveType> { none };
		}
	}

	std::unique_ptr<IArchiveBuilder> ArchiveBuilderFactory::Create(const libbsarchpp::ArchiveType archiveType, const IModDto* modDto) const
	{
		switch (archiveType) {
			case TES3:
			case TES4:
			case FO3:
			case SSE:
				return std::make_unique<GeneralArchiveBuilder>(this->m_ArchiveBuilderHelper, modDto->Directory(), archiveType);
			case FO4:
			case SF:
				return std::make_unique<TexturelessArchiveBuilder>(this->m_ArchiveBuilderHelper, modDto->Directory(), archiveType);
			case FO4dds:
			case SFdds:
				return std::make_unique<TextureArchiveBuilder>(this->m_ArchiveBuilderHelper, modDto->Directory(), archiveType);
			case none:
			default:
				return std::make_unique<NullArchiveBuilder>();
		}
	}
} // namespace BsaPacker
