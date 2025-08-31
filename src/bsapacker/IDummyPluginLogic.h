#ifndef IDUMMYPLUGINLOGIC_H
#define IDUMMYPLUGINLOGIC_H

#include <QString>
#include <array>
#include <libbsarchpp/enums.h>

namespace BsaPacker
{
	class IDummyPluginLogic
	{
	public:
		virtual ~IDummyPluginLogic() = default;
		[[nodiscard]] virtual bool canCreateDummyESP(const QString& fileNameNoExtension, const libbsarchpp::ArchiveType type) const = 0;
		[[nodiscard]] virtual bool canCreateDummyESL(const QString& fileNameNoExtension, const libbsarchpp::ArchiveType type) const = 0;
	};
}

#endif // IDUMMYPLUGINLOGIC_H
