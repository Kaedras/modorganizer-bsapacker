#ifndef IARCHIVEAUTOSERVICE_H
#define IARCHIVEAUTOSERVICE_H

#include <libbsarchppWrapper.h>
#include <bsapacker/IModDto.h>

namespace BsaPacker
{
	class IArchiveAutoService
	{
	public:
		virtual ~IArchiveAutoService() = default;
		virtual bool CreateBSA(libbsarch::libbsarchppWrapper*, const QString&, libbsarchpp::ArchiveType) const = 0;
	};
}

#endif // IARCHIVEAUTOSERVICE_H
