#include <bsapacker/IArchiveBuilderFactory.h>
#include <gmock/gmock.h>

using namespace BsaPacker;

class MockArchiveBuilderFactory : public IArchiveBuilderFactory
{
public:
	MOCK_METHOD(std::vector<libbsarchpp::ArchiveType>, GetArchiveTypes, (const IModDto*), (const, override));
	MOCK_METHOD(std::unique_ptr<IArchiveBuilder>, Create, (libbsarchpp::ArchiveType, const IModDto*), (const, override));
};
