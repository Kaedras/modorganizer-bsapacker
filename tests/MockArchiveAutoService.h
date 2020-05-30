#include <bsapacker/IArchiveAutoService.h>
#include <gmock/gmock.h>

using namespace BsaPacker;

class MockArchiveAutoService : public IArchiveAutoService
{
public:
	MOCK_METHOD(void, CreateBSA, (BSArchiveAuto*, const QString&, bsa_archive_type_e), (const, override));
};