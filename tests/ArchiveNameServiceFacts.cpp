#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "ArchiveNameService.h"
#include "MockModContext.h"
#include "ModDto.h"
#include "NexusId.h"

using namespace BsaPacker;
using libbsarchpp::ArchiveType;
using ::testing::NaggyMock;
using ::testing::Eq;
using ::testing::Return;

namespace BsaPackerTests
{
	class ArchiveNameServiceFacts : public ::testing::Test
	{
	protected:
		void SetUp() override {
			naggyMockModContext = new NaggyMock<MockModContext>();
		}

		void TearDown() override {
			delete naggyMockModContext;
		}

		NaggyMock<MockModContext>* naggyMockModContext;
	};

	TEST_F(ArchiveNameServiceFacts, Ctor_Always_Constructs)
	{
		EXPECT_NO_THROW(
			auto result = ArchiveNameService(
				naggyMockModContext
			);
		);
	}

	TEST_F(ArchiveNameServiceFacts, GetFileExtension_WhenNexusIdIsMorrowind_Returnsbsa)
	{
		// Arrange
		auto sut = ArchiveNameService(
				naggyMockModContext);
		ON_CALL(*naggyMockModContext, GetNexusId())
			.WillByDefault(Return(NexusId::Morrowind));

		// Act
		auto result = sut.GetFileExtension();

		// Assert
		EXPECT_EQ(".bsa", result.toStdString());
	}

	TEST_F(ArchiveNameServiceFacts, GetFileExtension_WhenNexusIdIsOblivion_Returnsbsa)
	{
		// Arrange
		auto sut = ArchiveNameService(
				naggyMockModContext);
		ON_CALL(*naggyMockModContext, GetNexusId())
			.WillByDefault(Return(NexusId::Oblivion));

		// Act
		auto result = sut.GetFileExtension();

		// Assert
		EXPECT_EQ(".bsa", result.toStdString());
	}

	TEST_F(ArchiveNameServiceFacts, GetFileExtension_WhenNexusIdIsFallout3_Returnsbsa)
	{
		// Arrange
		auto sut = ArchiveNameService(
				naggyMockModContext);
		ON_CALL(*naggyMockModContext, GetNexusId())
			.WillByDefault(Return(NexusId::Fallout3));

		// Act
		auto result = sut.GetFileExtension();

		// Assert
		EXPECT_EQ(".bsa", result.toStdString());
	}

	TEST_F(ArchiveNameServiceFacts, GetFileExtension_WhenNexusIdIsNewVegas_Returnsbsa)
	{
		// Arrange
		auto sut = ArchiveNameService(
				naggyMockModContext);
		ON_CALL(*naggyMockModContext, GetNexusId())
			.WillByDefault(Return(NexusId::NewVegas));

		// Act
		auto result = sut.GetFileExtension();

		// Assert
		EXPECT_EQ(".bsa", result.toStdString());
	}

	TEST_F(ArchiveNameServiceFacts, GetFileExtension_WhenNexusIdIsSkyrim_Returnsbsa)
	{
		// Arrange
		auto sut = ArchiveNameService(
				naggyMockModContext);
		ON_CALL(*naggyMockModContext, GetNexusId())
			.WillByDefault(Return(NexusId::Skyrim));

		// Act
		auto result = sut.GetFileExtension();

		// Assert
		EXPECT_EQ(".bsa", result.toStdString());
	}

	TEST_F(ArchiveNameServiceFacts, GetFileExtension_WhenNexusIdIsSkyrimSE_Returnsbsa)
	{
		// Arrange
		auto sut = ArchiveNameService(
				naggyMockModContext);
		ON_CALL(*naggyMockModContext, GetNexusId())
			.WillByDefault(Return(NexusId::SkyrimSE));

		// Act
		auto result = sut.GetFileExtension();

		// Assert
		EXPECT_EQ(".bsa", result.toStdString());
	}

	TEST_F(ArchiveNameServiceFacts, GetFileExtension_WhenNexusIdIsFallout4_Returnsbsa)
	{
		// Arrange
		auto sut = ArchiveNameService(
				naggyMockModContext);
		ON_CALL(*naggyMockModContext, GetNexusId())
			.WillByDefault(Return(NexusId::Fallout4));

		// Act
		auto result = sut.GetFileExtension();

		// Assert
		EXPECT_EQ(".ba2", result.toStdString());
	}

	TEST_F(ArchiveNameServiceFacts, GetFileExtension_InvalidNexusId_Returnsbsa)
	{
		// Arrange
		auto sut = ArchiveNameService(
				naggyMockModContext);
		ON_CALL(*naggyMockModContext, GetNexusId())
			.WillByDefault(Return(0));

		// Act
		auto result = sut.GetFileExtension();

		// Assert
		EXPECT_EQ("", result.toStdString());
	}

	TEST_F(ArchiveNameServiceFacts, GetArchiveFullPath_WhenTypeIsbaFO4_ReturnsFullPathWithMainInfix)
	{
		// Arrange
		auto sut = ArchiveNameService(
				naggyMockModContext);
		auto type = ArchiveType::FO4;
		auto dto = ModDto(0, "C:/directory", "archive", ".ba2");
		ON_CALL(*naggyMockModContext, GetNexusId())
			.WillByDefault(Return(NexusId::Fallout4));

		// Act
		auto result = sut.GetArchiveFullPath(type, &dto);

		// Assert
		EXPECT_EQ("C:/directory/archive - Main.ba2", result.toStdString());
	}

	TEST_F(ArchiveNameServiceFacts, GetArchiveFullPath_WhenTypeIsbaFO4dds_ReturnsFullPathWithTextureInfix)
	{
		// Arrange
		auto sut = ArchiveNameService(
				naggyMockModContext);
		auto type = ArchiveType::FO4dds;
		auto dto = ModDto(0, "C:/directory", "archive", ".ba2");
		ON_CALL(*naggyMockModContext, GetNexusId())
			.WillByDefault(Return(NexusId::Fallout4));

		// Act
		auto result = sut.GetArchiveFullPath(type, &dto);

		// Assert
		EXPECT_EQ("C:/directory/archive - Textures.ba2", result.toStdString());
	}

	TEST_F(ArchiveNameServiceFacts, GetArchiveFullPath_WhenTypeIsbaTES3_ReturnsFullPathWithoutInfix)
	{
		// Arrange
		auto sut = ArchiveNameService(
				naggyMockModContext);
		auto type = ArchiveType::TES3;
		auto dto = ModDto(0, "C:/directory", "archive", ".ba2");
		ON_CALL(*naggyMockModContext, GetNexusId())
			.WillByDefault(Return(NexusId::Morrowind));

		// Act
		auto result = sut.GetArchiveFullPath(type, &dto);

		// Assert
		EXPECT_EQ("C:/directory/archive.bsa", result.toStdString());
	}

	TEST_F(ArchiveNameServiceFacts, GetArchiveFullPath_WhenTypeIsbaTES4_ReturnsFullPathWithoutInfix)
	{
		// Arrange
		auto sut = ArchiveNameService(
				naggyMockModContext);
		auto type = ArchiveType::TES3;
		auto dto = ModDto(0, "C:/directory", "archive", ".ba2");
		ON_CALL(*naggyMockModContext, GetNexusId())
			.WillByDefault(Return(NexusId::Oblivion));

		// Act
		auto result = sut.GetArchiveFullPath(type, &dto);

		// Assert
		EXPECT_EQ("C:/directory/archive.bsa", result.toStdString());
	}

	TEST_F(ArchiveNameServiceFacts, GetArchiveFullPath_WhenTypeIsbaFO3_ReturnsFullPathWithoutInfix)
	{
		// Arrange
		auto sut = ArchiveNameService(
				naggyMockModContext);
		auto type = ArchiveType::FO3;
		auto dto = ModDto(0, "C:/directory", "archive", ".ba2");
		ON_CALL(*naggyMockModContext, GetNexusId())
			.WillByDefault(Return(NexusId::Fallout3));

		// Act
		auto result = sut.GetArchiveFullPath(type, &dto);

		// Assert
		EXPECT_EQ("C:/directory/archive.bsa", result.toStdString());
	}

	TEST_F(ArchiveNameServiceFacts, GetArchiveFullPath_WhenTypeIsbaSSE_ReturnsFullPathWithoutInfix)
	{
		// Arrange
		auto sut = ArchiveNameService(
				naggyMockModContext);
		auto type = ArchiveType::SSE;
		auto dto = ModDto(0, "C:/directory", "archive", ".ba2");
		ON_CALL(*naggyMockModContext, GetNexusId())
			.WillByDefault(Return(NexusId::SkyrimSE));

		// Act
		auto result = sut.GetArchiveFullPath(type, &dto);

		// Assert
		EXPECT_EQ("C:/directory/archive.bsa", result.toStdString());
	}
}
