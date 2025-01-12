#ifndef MOCKFILEWRITERSERVICE_H
#define MOCKFILEWRITERSERVICE_H

#include <bsapacker/IFileWriterService.h>
#include "gmock/gmock.h"

using namespace BsaPacker;

class MockFileWriterService : public IFileWriterService
{
public:
	MOCK_METHOD(bool, Write, (const std::string&, const char*, uint32_t), (const, override));
};
#endif // MOCKFILEWRITERSERVICE_H
