// Fill out your copyright notice in the Description page of Project Settings.


#include "NdisplayPoiActor.h"
#include "Components/LineBatchComponent.h"
#include "Components/WidgetComponent.h"
#include "Components/BillboardComponent.h"
#include "Components/MaterialBillboardComponent.h"



//构造函数
ANdisplayPoiActor::ANdisplayPoiActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



	/*初始化根组件*/
	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));

	/*初始化LineBatch组件*/
	LineBatchComp = CreateDefaultSubobject<ULineBatchComponent>(TEXT("LineBatchComp"));
	LineBatchComp->SetupAttachment(RootComp);

	/*初始化MaterialBillBorad组件*/
	MaterialBiilboradComp = CreateDefaultSubobject<UMaterialBillboardComponent>(TEXT("MaterialBillboradComp"));
	MaterialBiilboradComp->SetupAttachment(RootComp);


}

// Called when the game starts or when spawned
void ANdisplayPoiActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANdisplayPoiActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



/*根据坐标数组绘制线条*/
void ANdisplayPoiActor::DrawNdisplayPoiLine(TArray<FVector> LinePositionArr)
{
	//创建结构体数组
	TArray<FBatchedLine> LinesArr;

	//给数组初始化结构体成员变量
	for (int32 i = 0; i < LinePositionArr.Num() - 1; i++) 
	{

		FBatchedLine OneLineTemp;
		OneLineTemp.Start = LinePositionArr[i];
		OneLineTemp.End = LinePositionArr[i + 1];
		OneLineTemp.Color = LineColor;
		OneLineTemp.Thickness = LineThickness;
		OneLineTemp.RemainingLifeTime = 1.f;

		LinesArr.Add(OneLineTemp);

	}

	//调用官方组件绘制线条函数
	LineBatchComp->DrawLines(LinesArr);


}



/*清除所有已绘制线条*/
void ANdisplayPoiActor::ClearAllNdisplayPoiLines()
{

	/*调用官方组件清除线条函数*/
	LineBatchComp->Flush();

}




