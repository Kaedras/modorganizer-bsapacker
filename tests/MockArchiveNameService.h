#ifndef MOCKARCHIVENAMESERVICE_H
#define MOCKARCHIVENAMESERVICE_H

#include <bsapacker/IArchiveNameService.h>
#include <gmock/gmock.h>

using namespace BsaPacker;

class MockArchiveNameService : public IArchiveNameService
{
public:
	MOCK_METHOD(QString, GetFileExtension, (), (const, override));
	MOCK_METHOD(QString, GetArchiveFullPath, (libbsarchpp::ArchiveType, const IModDto*), (const, override));
	MOCK_METHOD(QString, Infix, (libbsarchpp::ArchiveType type), (const, override));
	MOCK_METHOD(QString, Suffix, (const QString& pathNoExt), (const, override));
};
#endif // MOCKARCHIVENAMESERVICE_H
