// Created by YetiTech Studios.

#pragma once

#include "CoreMinimal.h"
#include "GameLiftClientTypes.h"

// AWS includes
#include "aws/gamelift/GameLiftClient.h"
#include "aws/gamelift/model/CreateGameSessionResult.h"
#include "aws/core/auth/AWSCredentialsProvider.h"
//

#include "GameLiftClientApi.generated.h"

UENUM(BlueprintType)
enum class EActivateStatus : uint8
{
	/* Successfully activated. */
	ACTIVATE_Success				UMETA(DisplayName = "Success"),

	/* GameLiftClient was null. Make sure you called CreateGameLiftObject function. */
	ACTIVATE_NoGameLift				UMETA(DisplayName = "Null GameLift"),

	/* Delegate that was suppose to call when outcome is a success was not binded to any function. */
	ACTIVATE_NoSuccessCallback		UMETA(DisplayName = "Success Delegate not bound"),

	/* Delegate that was suppose to call when outcome is a failure was not binded to any function. */
	ACTIVATE_NoFailCallback			UMETA(DisplayName = "Failed Delegate not bound")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreateGameSessionSuccess, const FGameLiftCreateGameSessionResult&, CreateGameSessionResult);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreateGameSessionFailed, const FString&, ErrorMessage);
UCLASS()
class GAMELIFTCLIENTSDK_API UGameLiftCreateGameSession : public UObject
{
	GENERATED_BODY()

	friend class UGameLiftClientObject;

public:
	UPROPERTY(BlueprintAssignable, Category = "GameLift CreateGameSession")
	FOnCreateGameSessionSuccess OnCreateGameSessionSuccess;

	UPROPERTY(BlueprintAssignable, Category = "GameLift CreateGameSession")
	FOnCreateGameSessionFailed OnCreateGameSessionFailed;

private:
	Aws::GameLift::GameLiftClient* GameLiftClient;
	const FGameLiftCreateGameSessionConfig* CreateGameSessionConfig;

	static UGameLiftCreateGameSession* CreateGameSession(const FGameLiftCreateGameSessionConfig& CreateGameSessionConfig);

public:
	UFUNCTION(BlueprintCallable, Category = "GameLift CreateGameSession")
	EActivateStatus Activate();

private:
	void OnCreateGameSession(const Aws::GameLift::GameLiftClient* Client, const Aws::GameLift::Model::CreateGameSessionRequest& Request, const Aws::GameLift::Model::CreateGameSessionOutcome& Outcome, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& Context);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDescribeGameSessionDetailsSuccess, const FGameLiftDescribeGameSessionDetailsResult&, DescribeGameSessionDetailsResult);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDescribeGameSessionDetailsFailed, const FString&, ErrorMessage);
UCLASS()
class GAMELIFTCLIENTSDK_API UGameLiftDescribeGameSessionDetails : public UObject
{
	GENERATED_BODY()

	friend class UGameLiftClientObject;

public:

	UPROPERTY(BlueprintAssignable, Category = "GameLift DescribeGameSessionDetails")
	FOnDescribeGameSessionDetailsSuccess OnDescribeGameSessionDetailsSuccess;
	
	UPROPERTY(BlueprintAssignable, Category = "GameLift DescribeGameSessionDetails")
	FOnDescribeGameSessionDetailsFailed OnDescribeGameSessionDetailsFailed;

private:
	Aws::GameLift::GameLiftClient* GameLiftClient;
	const FGameLiftDescribeGameSessionDetailsConfig* DescribeGameSessionDetailsConfig;

	static UGameLiftDescribeGameSessionDetails* DescribeGameSessionDetails(const FGameLiftDescribeGameSessionDetailsConfig& DescribeGameSessionDetailsConfig);

public:
	UFUNCTION(BlueprintCallable, Category = "GameLift DescribeGameSessionDetials")
	EActivateStatus Activate();	

private:
	void OnDescribeGameSessionDetails(const Aws::GameLift::GameLiftClient* Client, const Aws::GameLift::Model::DescribeGameSessionDetailsRequest& Request, const Aws::GameLift::Model::DescribeGameSessionDetailsOutcome& Outcome, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& Context);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreatePlayerSessionSuccess, const FGameLiftCreatePlayerSessionResult&, CreateGameSessionResult);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreatePlayerSessionFailed, const FString&, ErrorMessage);
UCLASS()
class GAMELIFTCLIENTSDK_API UGameLiftCreatePlayerSession : public UObject
{
	GENERATED_BODY()

	friend class UGameLiftClientObject;

public:

	UPROPERTY(BlueprintAssignable, Category = "GameLift CreatePlayerSession")
	FOnCreatePlayerSessionSuccess OnCreatePlayerSessionSuccess;

	UPROPERTY(BlueprintAssignable, Category = "GameLift CreatePlayerSession")
	FOnCreatePlayerSessionFailed OnCreatePlayerSessionFailed;

private:
	Aws::GameLift::GameLiftClient* GameLiftClient;
	const FGameLiftCreatePlayerSessionConfig* CreatePlayerSessionConfig;

	static UGameLiftCreatePlayerSession* CreatePlayerSession(const FGameLiftCreatePlayerSessionConfig& CreatePlayerSessionConfig);

public:
	UFUNCTION(BlueprintCallable, Category = "GameLift CreatePlayerSession")
	EActivateStatus Activate();

private:
	void OnCreatePlayerSession(const Aws::GameLift::GameLiftClient* Client, const Aws::GameLift::Model::CreatePlayerSessionRequest& Request, const Aws::GameLift::Model::CreatePlayerSessionOutcome& Outcome, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& Context);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDescribeGameSessionQueuesSuccess, const FGameLiftDescribeGameSessionQueuesResult&, DescribeGameSessionQueuesResult);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDescribeGameSessionQueuesFailed, const FString&, ErrorMessage);
UCLASS()
class GAMELIFTCLIENTSDK_API UGameLiftDescribeGameSessionQueues : public UObject
{
	GENERATED_BODY()

	friend class UGameLiftClientObject;

public:

	UPROPERTY(BlueprintAssignable, Category = "GameLift DescribeGameSessionQueues")
	FOnDescribeGameSessionQueuesSuccess OnDescribeGameSessionQueuesSuccess;

	UPROPERTY(BlueprintAssignable, Category = "GameLift DescribeGameSessionQueues")
	FOnDescribeGameSessionQueuesFailed OnDescribeGameSessionQueuesFailed;

private:
	Aws::GameLift::GameLiftClient* GameLiftClient;
	const FGameLiftDescribeGameSessionQueuesConfig* DescribeGameSessionQueuesConfig;

	static UGameLiftDescribeGameSessionQueues* DescribeGameSessionQueues(const FGameLiftDescribeGameSessionQueuesConfig& DescribeGameSessionQueuesConfig);

public:
	UFUNCTION(BlueprintCallable, Category = "GameLift DescribeGameSessionQueues")
	EActivateStatus Activate();

private:
	void OnDescribeGameSessionQueues(const Aws::GameLift::GameLiftClient* Client, const Aws::GameLift::Model::DescribeGameSessionQueuesRequest& Request, const Aws::GameLift::Model::DescribeGameSessionQueuesOutcome& Outcome, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& Context);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSearchGameSessionsSuccess, const FGameLiftSearchGameSessionsResult&, SearchGameSessionsResult);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSearchGameSessionsFailed, const FString&, ErrorMessage);
UCLASS()
class GAMELIFTCLIENTSDK_API UGameLiftSearchGameSessions : public UObject
{
	GENERATED_BODY()

	friend class UGameLiftClientObject;

public:

	UPROPERTY(BlueprintAssignable, Category = "GameLift SearchGameSessions")
	FOnSearchGameSessionsSuccess OnSearchGameSessionsSuccess;

	UPROPERTY(BlueprintAssignable, Category = "GameLift SearchGameSessions")
	FOnSearchGameSessionsFailed OnSearchGameSessionsFailed;

private:
	Aws::GameLift::GameLiftClient* GameLiftClient;
	const FGameLiftSearchGameSessionsConfig* SearchGameSessionsConfig;

	static UGameLiftSearchGameSessions* SearchGameSessions(const FGameLiftSearchGameSessionsConfig& SearchGameSessionsConfig);

public:
	UFUNCTION(BlueprintCallable, Category = "GameLift SearchGameSessions")
	EActivateStatus Activate();

private:
	void OnSearchGameSessions(const Aws::GameLift::GameLiftClient* Client, const Aws::GameLift::Model::SearchGameSessionsRequest& Request, const Aws::GameLift::Model::SearchGameSessionsOutcome& Outcome, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& Context);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStartGameSessionPlacementSuccess, const FGameLiftStartGameSessionPlacementResult&, StartGameSessionPlacementResult);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStartGameSessionPlacementFailed, const FString&, ErrorMessage);
UCLASS()
class GAMELIFTCLIENTSDK_API UGameLiftStartGameSessionPlacement : public UObject
{
	GENERATED_BODY()

	friend class UGameLiftClientObject;

public:

	UPROPERTY(BlueprintAssignable, Category = "GameLift StartGameSessionPlacement")
	FOnStartGameSessionPlacementSuccess OnStartGameSessionPlacementSuccess;

	UPROPERTY(BlueprintAssignable, Category = "GameLift StartGameSessionPlacement")
	FOnStartGameSessionPlacementFailed OnStartGameSessionPlacementFailed;

private:
	Aws::GameLift::GameLiftClient* GameLiftClient;
	const FGameLiftStartGameSessionPlacementConfig* StartGameSessionPlacementConfig;

	static UGameLiftStartGameSessionPlacement* StartGameSessionPlacement(const FGameLiftStartGameSessionPlacementConfig& StartGameSessionPlacementConfig);

public:
	UFUNCTION(BlueprintCallable, Category = "GameLift StartGameSessionPlacement")
	EActivateStatus Activate();

private:
	void OnStartGameSessionPlacement(const Aws::GameLift::GameLiftClient* Client, const Aws::GameLift::Model::StartGameSessionPlacementRequest& Request, const Aws::GameLift::Model::StartGameSessionPlacementOutcome& Outcome, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& Context);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDescribeGameSessionPlacementSuccess, const FGameLiftDescribeGameSessionPlacementResult&, DescribeGameSessionPlacementResult);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDescribeGameSessionPlacementFailed, const FString&, ErrorMessage);
UCLASS()
class GAMELIFTCLIENTSDK_API UGameLiftDescribeGameSessionPlacement : public UObject
{
	GENERATED_BODY()

	friend class UGameLiftClientObject;

public:

	UPROPERTY(BlueprintAssignable, Category = "GameLift DescribeGameSessionPlacement")
	FOnDescribeGameSessionPlacementSuccess OnDescribeGameSessionPlacementSuccess;

	UPROPERTY(BlueprintAssignable, Category = "GameLift DescribeGameSessionPlacement")
	FOnDescribeGameSessionPlacementFailed OnDescribeGameSessionPlacementFailed;

private:
	Aws::GameLift::GameLiftClient* GameLiftClient;
	const FGameLiftDescribeGameSessionPlacementConfig* DescribeGameSessionPlacementConfig;

	static UGameLiftDescribeGameSessionPlacement* DescribeGameSessionPlacement(const FGameLiftDescribeGameSessionPlacementConfig& DescribeGameSessionPlacementConfig);

public:
	UFUNCTION(BlueprintCallable, Category = "GameLift DescribeGameSessionPlacement")
	EActivateStatus Activate();

private:
	void OnDescribeGameSessionPlacement(const Aws::GameLift::GameLiftClient* Client, const Aws::GameLift::Model::DescribeGameSessionPlacementRequest& Request, const Aws::GameLift::Model::DescribeGameSessionPlacementOutcome& Outcome, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& Context);
};
