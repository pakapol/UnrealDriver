// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MULTIBOX_BoxActor_generated_h
#error "BoxActor.generated.h already included, missing '#pragma once' in BoxActor.h"
#endif
#define MULTIBOX_BoxActor_generated_h

#define multibox_Source_multibox_BoxActor_h_13_RPC_WRAPPERS
#define multibox_Source_multibox_BoxActor_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define multibox_Source_multibox_BoxActor_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABoxActor(); \
	friend MULTIBOX_API class UClass* Z_Construct_UClass_ABoxActor(); \
public: \
	DECLARE_CLASS(ABoxActor, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/multibox"), NO_API) \
	DECLARE_SERIALIZER(ABoxActor) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define multibox_Source_multibox_BoxActor_h_13_INCLASS \
private: \
	static void StaticRegisterNativesABoxActor(); \
	friend MULTIBOX_API class UClass* Z_Construct_UClass_ABoxActor(); \
public: \
	DECLARE_CLASS(ABoxActor, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/multibox"), NO_API) \
	DECLARE_SERIALIZER(ABoxActor) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define multibox_Source_multibox_BoxActor_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABoxActor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABoxActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABoxActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABoxActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABoxActor(ABoxActor&&); \
	NO_API ABoxActor(const ABoxActor&); \
public:


#define multibox_Source_multibox_BoxActor_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABoxActor(ABoxActor&&); \
	NO_API ABoxActor(const ABoxActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABoxActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABoxActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABoxActor)


#define multibox_Source_multibox_BoxActor_h_13_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__pComponent() { return STRUCT_OFFSET(ABoxActor, pComponent); }


#define multibox_Source_multibox_BoxActor_h_10_PROLOG
#define multibox_Source_multibox_BoxActor_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	multibox_Source_multibox_BoxActor_h_13_PRIVATE_PROPERTY_OFFSET \
	multibox_Source_multibox_BoxActor_h_13_RPC_WRAPPERS \
	multibox_Source_multibox_BoxActor_h_13_INCLASS \
	multibox_Source_multibox_BoxActor_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define multibox_Source_multibox_BoxActor_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	multibox_Source_multibox_BoxActor_h_13_PRIVATE_PROPERTY_OFFSET \
	multibox_Source_multibox_BoxActor_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	multibox_Source_multibox_BoxActor_h_13_INCLASS_NO_PURE_DECLS \
	multibox_Source_multibox_BoxActor_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID multibox_Source_multibox_BoxActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
