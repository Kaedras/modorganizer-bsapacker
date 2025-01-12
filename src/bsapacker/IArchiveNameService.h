#ifndef IARCHIVENAMESERVICE_H
#define IARCHIVENAMESERVICE_H

#include <QString>
#include <libbsarchpp/enums.h>
#include <bsapacker/IModDto.h>

namespace BsaPacker
{
	class IArchiveNameService
	{
	public:
		virtual ~IArchiveNameService() = default;
		virtual QString GetFileExtension() const = 0;
		virtual QString GetArchiveFullPath(libbsarchpp::ArchiveType, const IModDto*) const = 0;
		virtual QString Infix(libbsarchpp::ArchiveType type) const = 0;
		virtual QString Suffix(const QString& pathNoExt) const = 0;
	};
}

#endif // !IARCHIVENAMESERVICE_H
