#ifndef IARCHIVEAUTOSERVICE_H
#define IARCHIVEAUTOSERVICE_H

#include <bsapacker/IModDto.h>
#include "libbsarchppWrapper.h"

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
