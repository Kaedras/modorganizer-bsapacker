#include <bsapacker/IDummyPluginLogic.h>
#include "gmock/gmock.h"

using namespace BsaPacker;

class MockDummyPluginLogic : public IDummyPluginLogic
{
public:
	MOCK_METHOD(bool, canCreateDummyESP, (const QString &, const libbsarchpp::ArchiveType), (const, override));
	MOCK_METHOD(bool, canCreateDummyESL, (const QString &, const libbsarchpp::ArchiveType), (const, override));
};
