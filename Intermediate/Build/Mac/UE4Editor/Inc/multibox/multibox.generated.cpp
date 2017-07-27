// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "multibox.generated.dep.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCode1multibox() {}
#if USE_COMPILED_IN_NATIVES
// Cross Module References
	ENGINE_API class UClass* Z_Construct_UClass_AActor();
	ENGINE_API class UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_AGameModeBase();

	MULTIBOX_API class UClass* Z_Construct_UClass_ABoxActor_NoRegister();
	MULTIBOX_API class UClass* Z_Construct_UClass_ABoxActor();
	MULTIBOX_API class UClass* Z_Construct_UClass_ACompositeBoxActor_NoRegister();
	MULTIBOX_API class UClass* Z_Construct_UClass_ACompositeBoxActor();
	MULTIBOX_API class UClass* Z_Construct_UClass_AmultiboxGameModeBase_NoRegister();
	MULTIBOX_API class UClass* Z_Construct_UClass_AmultiboxGameModeBase();
	MULTIBOX_API class UPackage* Z_Construct_UPackage__Script_multibox();
	void ABoxActor::StaticRegisterNativesABoxActor()
	{
	}
	UClass* Z_Construct_UClass_ABoxActor_NoRegister()
	{
		return ABoxActor::StaticClass();
	}
	UClass* Z_Construct_UClass_ABoxActor()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_multibox();
			OuterClass = ABoxActor::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_pComponent = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("pComponent"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(pComponent, ABoxActor), 0x00400000000a0009, Z_Construct_UClass_UBoxComponent_NoRegister());
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				static TCppClassTypeInfo<TCppClassTypeTraits<ABoxActor> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("BoxActor.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("BoxActor.h"));
				MetaData->SetValue(NewProp_pComponent, TEXT("Category"), TEXT("BoxActor"));
				MetaData->SetValue(NewProp_pComponent, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_pComponent, TEXT("ModuleRelativePath"), TEXT("BoxActor.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABoxActor, 3739569195);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABoxActor(Z_Construct_UClass_ABoxActor, &ABoxActor::StaticClass, TEXT("/Script/multibox"), TEXT("ABoxActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABoxActor);
	void ACompositeBoxActor::StaticRegisterNativesACompositeBoxActor()
	{
	}
	UClass* Z_Construct_UClass_ACompositeBoxActor_NoRegister()
	{
		return ACompositeBoxActor::StaticClass();
	}
	UClass* Z_Construct_UClass_ACompositeBoxActor()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_multibox();
			OuterClass = ACompositeBoxActor::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


				static TCppClassTypeInfo<TCppClassTypeTraits<ACompositeBoxActor> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("CompositeBoxActor.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("CompositeBoxActor.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACompositeBoxActor, 1984645789);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACompositeBoxActor(Z_Construct_UClass_ACompositeBoxActor, &ACompositeBoxActor::StaticClass, TEXT("/Script/multibox"), TEXT("ACompositeBoxActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACompositeBoxActor);
	void AmultiboxGameModeBase::StaticRegisterNativesAmultiboxGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AmultiboxGameModeBase_NoRegister()
	{
		return AmultiboxGameModeBase::StaticClass();
	}
	UClass* Z_Construct_UClass_AmultiboxGameModeBase()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AGameModeBase();
			Z_Construct_UPackage__Script_multibox();
			OuterClass = AmultiboxGameModeBase::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900288;


				static TCppClassTypeInfo<TCppClassTypeTraits<AmultiboxGameModeBase> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("multiboxGameModeBase.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("multiboxGameModeBase.h"));
				MetaData->SetValue(OuterClass, TEXT("ShowCategories"), TEXT("Input|MouseInput Input|TouchInput"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AmultiboxGameModeBase, 1575340155);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AmultiboxGameModeBase(Z_Construct_UClass_AmultiboxGameModeBase, &AmultiboxGameModeBase::StaticClass, TEXT("/Script/multibox"), TEXT("AmultiboxGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AmultiboxGameModeBase);
	UPackage* Z_Construct_UPackage__Script_multibox()
	{
		static UPackage* ReturnPackage = nullptr;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), nullptr, FName(TEXT("/Script/multibox")), false, false));
			ReturnPackage->SetPackageFlags(PKG_CompiledIn | 0x00000000);
			FGuid Guid;
			Guid.A = 0xCE36A8DF;
			Guid.B = 0xDE1B4F7C;
			Guid.C = 0x00000000;
			Guid.D = 0x00000000;
			ReturnPackage->SetGuid(Guid);

		}
		return ReturnPackage;
	}
#endif
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
