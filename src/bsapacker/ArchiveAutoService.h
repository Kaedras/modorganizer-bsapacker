#ifndef ARCHIVEAUTOSERVICE_H
#define ARCHIVEAUTOSERVICE_H

#include "bsapacker_global.h"
#include <bsapacker/IArchiveAutoService.h>

namespace BsaPacker
{
	class BSAPACKER_EXPORT ArchiveAutoService : public IArchiveAutoService
	{
	public:
		ArchiveAutoService() = default;
		bool CreateBSA(libbsarch::libbsarchppWrapper* archive, const QString& archiveName, libbsarchpp::ArchiveType type) const override;
	};
} // namespace BsaPacker

#endif // ARCHIVEAUTOSERVICE_H
