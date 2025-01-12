#ifndef MOCKSETTINGSSERVICE_H
#define MOCKSETTINGSSERVICE_H

#include <bsapacker/ISettingsService.h>
#include <gmock/gmock.h>

using namespace BsaPacker;

class MockSettingsService : public ISettingsService
{
public:
	MOCK_METHOD(QVariant, GetPluginSetting, (const QString&), (const, override));
};
#endif // MOCKSETTINGSSERVICE_H
