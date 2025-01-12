#include <bsapacker/NullArchiveBuilder.h>

namespace BsaPacker
{
	uint32_t NullArchiveBuilder::setFiles()
	{
		return 0;
	}

	void NullArchiveBuilder::setShareData(const bool)
	{
	}

	std::vector<std::unique_ptr<libbsarch::libbsarchppWrapper>> NullArchiveBuilder::getArchives()
	{
		return {};
	}

	uint32_t NullArchiveBuilder::getFileCount() const
	{
		return 0;
	}

	QString NullArchiveBuilder::getRootPath() const
	{
		return QString();
	}

	void NullArchiveBuilder::cancel()
	{
	}
} // namespace BsaPacker
