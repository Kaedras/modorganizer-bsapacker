#ifndef MOCKHIDELOOSEASSETSERVICE_H
#define MOCKHIDELOOSEASSETSERVICE_H

#include "bsapacker/IHideLooseAssetService.h"
#include <gmock/gmock.h>

using namespace BsaPacker;

class MockHideLooseAssetService : public IHideLooseAssetService
{
public:
	MOCK_METHOD(bool, HideLooseAssets, (const QDir&), (const, override));
};
#endif // MOCKHIDELOOSEASSETSERVICE_H
