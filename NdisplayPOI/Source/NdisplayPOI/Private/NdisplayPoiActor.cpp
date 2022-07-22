// Fill out your copyright notice in the Description page of Project Settings.


#include "NdisplayPoiActor.h"
#include "Components/LineBatchComponent.h"
#include "Components/WidgetComponent.h"
#include "Components/BillboardComponent.h"
#include "Components/MaterialBillboardComponent.h"



//���캯��
ANdisplayPoiActor::ANdisplayPoiActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



	/*��ʼ�������*/
	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));

	/*��ʼ��LineBatch���*/
	LineBatchComp = CreateDefaultSubobject<ULineBatchComponent>(TEXT("LineBatchComp"));
	LineBatchComp->SetupAttachment(RootComp);

	/*��ʼ��MaterialBillBorad���*/
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



/*�������������������*/
void ANdisplayPoiActor::DrawNdisplayPoiLine(TArray<FVector> LinePositionArr)
{
	//�����ṹ������
	TArray<FBatchedLine> LinesArr;

	//�������ʼ���ṹ���Ա����
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

	//���ùٷ����������������
	LineBatchComp->DrawLines(LinesArr);


}



/*��������ѻ�������*/
void ANdisplayPoiActor::ClearAllNdisplayPoiLines()
{

	/*���ùٷ���������������*/
	LineBatchComp->Flush();

}




