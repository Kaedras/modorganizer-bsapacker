#ifndef MOCKOVERRIDEFILESERVICE_H
#define MOCKOVERRIDEFILESERVICE_H

#include <bsapacker/IOverrideFileService.h>
#include <gmock/gmock.h>

using namespace BsaPacker;

class MockOverrideFileService : public IOverrideFileService
{
public:
    MOCK_METHOD(bool, CreateOverrideFile, (const int nexusId, const QString& modPath, const QStringList& archiveNames),
                (const, override));
};

#endif //MOCKOVERRIDEFILESERVICE_H
