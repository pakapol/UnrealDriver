// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CAR_CarActor_generated_h
#error "CarActor.generated.h already included, missing '#pragma once' in CarActor.h"
#endif
#define CAR_CarActor_generated_h

#define car_Source_car_CarActor_h_12_RPC_WRAPPERS
#define car_Source_car_CarActor_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define car_Source_car_CarActor_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACarActor(); \
	friend CAR_API class UClass* Z_Construct_UClass_ACarActor(); \
public: \
	DECLARE_CLASS(ACarActor, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/car"), NO_API) \
	DECLARE_SERIALIZER(ACarActor) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define car_Source_car_CarActor_h_12_INCLASS \
private: \
	static void StaticRegisterNativesACarActor(); \
	friend CAR_API class UClass* Z_Construct_UClass_ACarActor(); \
public: \
	DECLARE_CLASS(ACarActor, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/car"), NO_API) \
	DECLARE_SERIALIZER(ACarActor) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define car_Source_car_CarActor_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACarActor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACarActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACarActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACarActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACarActor(ACarActor&&); \
	NO_API ACarActor(const ACarActor&); \
public:


#define car_Source_car_CarActor_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACarActor(ACarActor&&); \
	NO_API ACarActor(const ACarActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACarActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACarActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACarActor)


#define car_Source_car_CarActor_h_12_PRIVATE_PROPERTY_OFFSET
#define car_Source_car_CarActor_h_9_PROLOG
#define car_Source_car_CarActor_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	car_Source_car_CarActor_h_12_PRIVATE_PROPERTY_OFFSET \
	car_Source_car_CarActor_h_12_RPC_WRAPPERS \
	car_Source_car_CarActor_h_12_INCLASS \
	car_Source_car_CarActor_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define car_Source_car_CarActor_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	car_Source_car_CarActor_h_12_PRIVATE_PROPERTY_OFFSET \
	car_Source_car_CarActor_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	car_Source_car_CarActor_h_12_INCLASS_NO_PURE_DECLS \
	car_Source_car_CarActor_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID car_Source_car_CarActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
