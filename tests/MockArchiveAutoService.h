#include <bsapacker/IArchiveAutoService.h>
#include <gmock/gmock.h>

using namespace BsaPacker;

class MockArchiveAutoService : public IArchiveAutoService
{
public:
	MOCK_METHOD(bool, CreateBSA, (libbsarch::libbsarchppWrapper *, const QString &, libbsarchpp::ArchiveType), (const, override));
};
