#ifndef IARCHIVEBUILDER_H
#define IARCHIVEBUILDER_H

#include <libbsarchppWrapper.h>
#include <bsapacker/IEmitsValueChanged.h>

namespace BsaPacker
{
	class IArchiveBuilder : public IEmitsValueChanged
	{
		Q_OBJECT
			Q_INTERFACES(BsaPacker::IEmitsValueChanged)

	public:
		virtual ~IArchiveBuilder() = default;
		virtual uint32_t setFiles() = 0;
		virtual void setShareData(bool) = 0;
		[[nodiscard]] virtual std::vector<std::unique_ptr<libbsarch::libbsarchppWrapper>> getArchives() = 0;
		[[nodiscard]] virtual uint32_t getFileCount() const = 0;
		[[nodiscard]] virtual QString getRootPath() const = 0;
	};
}  // namespace BsaPacker

#endif // IARCHIVEBUILDER_H
