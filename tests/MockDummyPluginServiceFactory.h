#ifndef MOCKDUMMYPLUGINSERVICEFACTORY_H
#define MOCKDUMMYPLUGINSERVICEFACTORY_H

#include <bsapacker/IDummyPluginServiceFactory.h>
#include <gmock/gmock.h>

using namespace BsaPacker;

class MockDummyPluginServiceFactory : public IDummyPluginServiceFactory
{
public:
	MOCK_METHOD(std::unique_ptr<IDummyPluginService>, Create, (), (const, override));
};
#endif // MOCKDUMMYPLUGINSERVICEFACTORY_H
