#include <bsapacker/ArchiveBuilderFactory.h>

#include <bsapacker/GeneralArchiveBuilder.h>
#include <bsapacker/NullArchiveBuilder.h>
#include <bsapacker/TextureArchiveBuilder.h>
#include <bsapacker/TexturelessArchiveBuilder.h>
#include "NexusId.h"

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
				return std::vector{libbsarchpp::TES3 };
			case NexusId::Oblivion:
				return std::vector{libbsarchpp::TES4 };
			case NexusId::Fallout3:
			case NexusId::NewVegas:
			case NexusId::Skyrim:
			case NexusId::Enderal:
				return std::vector{libbsarchpp::FO3 };
			case NexusId::SkyrimSE:
			case NexusId::EnderalSE:
				return std::vector{libbsarchpp::SSE };
			case NexusId::Fallout4:
				return std::vector{libbsarchpp::FO4, libbsarchpp::FO4dds };
			case NexusId::Starfield:
				return std::vector{libbsarchpp::SF, libbsarchpp::SFdds };
			default:
				return std::vector{ libbsarchpp::none };
		}
	}

	std::unique_ptr<IArchiveBuilder> ArchiveBuilderFactory::Create(const libbsarchpp::ArchiveType archiveType, const IModDto* modDto) const
	{
		switch (archiveType) {
			case libbsarchpp::TES3:
			case libbsarchpp::TES4:
			case libbsarchpp::FO3:
			case libbsarchpp::SSE:
				return std::make_unique<GeneralArchiveBuilder>(this->m_ArchiveBuilderHelper, modDto->Directory(), archiveType);
			case libbsarchpp::FO4:
			case libbsarchpp::SF:
				return std::make_unique<TexturelessArchiveBuilder>(this->m_ArchiveBuilderHelper, modDto->Directory(), archiveType);
			case libbsarchpp::FO4dds:
			case libbsarchpp::SFdds:
				return std::make_unique<TextureArchiveBuilder>(this->m_ArchiveBuilderHelper, modDto->Directory(), archiveType);
			case libbsarchpp::none:
			default:
				return std::make_unique<NullArchiveBuilder>();
		}
	}
} // namespace BsaPacker
