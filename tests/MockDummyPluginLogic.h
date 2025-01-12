#ifndef MOCKDUMMYPLUGINLOGIC_H
#define MOCKDUMMYPLUGINLOGIC_H

#include <bsapacker/IDummyPluginLogic.h>
#include "gmock/gmock.h"

using namespace BsaPacker;

class MockDummyPluginLogic : public IDummyPluginLogic
{
public:
	MOCK_METHOD(bool, canCreateDummyESP, (const QString& fileNameNoExtension, const libbsarchpp::ArchiveType type), (const, override));
	MOCK_METHOD(bool, canCreateDummyESL, (const QString& fileNameNoExtension, const libbsarchpp::ArchiveType type), (const, override));
};
#endif // MOCKDUMMYPLUGINLOGIC_H
