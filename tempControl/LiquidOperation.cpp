#include "LiquidOperation.h"

#include "Controller.h"
#include "Environment.h"
#include "Heater.h"
#include "LevelIndicator.h"
#include "LevelSensor.h"
#include "OnOffController.h"
#include "PIDController.h"
#include "Pot.h"
#include "PotFactory.h"
#include "TempIndicator.h"
#include "TempSensor.h"
#include "Timer.h"
#include "WaterInfo.h"

#define HEAT_TRANSFER_COEFFICIENT    0.0008
#define TEMP_OUTSIDE                 20.0

#define SEC_10                       10
#define SEC_20                       20
#define SEC_30                       30
#define SEC_50                       50

//---------------------------------------------------------
LiquidOperation::LiquidOperation()
{
}

//---------------------------------------------------------
LiquidOperation::~LiquidOperation() 
{
}

//---------------------------------------------------------
LiquidInfo* LiquidOperation::createWater()
{
	string ident;
	double mass;
	double temp;

	cout << ">���̎��ʎq�́H" << endl;
	cin >> ident;
	cout << ">���̎���(g)�́H " << endl;
	cin >> mass;
	cout << ">���̉��x(��)�́H " << endl;
	cin >> temp;

	WaterInfo* pWater = new WaterInfo( "��", ident, mass, temp );

	_ASSERT( pWater );
	return pWater;
}

//---------------------------------------------------------
void LiquidOperation::doExperiment()
{
	LiquidInfo* pLiquid1 = createWater();
	LiquidInfo* pLiquid2 = createWater();
	_ASSERT( pLiquid1 );
	_ASSERT( pLiquid2 );

	cout << "�y�����O�z" << endl;
	pLiquid1->showLiquid();
	pLiquid2->showLiquid();
	bool state = pLiquid1->add( pLiquid2 );
	if ( false == state ) {
		return;
	}
	cout << "�y������z" << endl;
	pLiquid1->showLiquid();

	double mass;
	cout << ">��菜������(g)�́H " << endl;
	cin >> mass;
	cout << "�y�����O�z" << endl;
	pLiquid1->showLiquid();
	pLiquid1->removeMass( mass );
	cout << "�y������z" << endl;
	pLiquid1->showLiquid();

	delete( pLiquid1 );
	delete( pLiquid2 );
}

//---------------------------------------------------------
void LiquidOperation::heatWater()
{
	// ��
	Environment environment( HEAT_TRANSFER_COEFFICIENT );
	environment.setTemp( TEMP_OUTSIDE );

	// �^�C�}�[�𐶐�
	Timer timer;

	// �|�b�g�𐶐�
	int type = 0;
	cout << ">�|�b�g��( 0:Standard, 1:Premium )�H" << endl;
	cin >> type;
	LiquidInfo* pWater = LiquidOperation::createWater();
	Pot* pPot = PotFactory::create( type, pWater );
	pPot->setEnviroment( environment );
	pPot->powerOn();

	// �^�X�N��ǉ�
	timer.addTask( pPot );

	cout << "���M�O" << endl;
	cout << " �����x=" << environment.getTemp() << endl;
	pPot->showLiquidInfo();

	cout << "���M��" << endl;
	pPot->turnHeaterOn();
	timer.start( SEC_10 );
	pPot->showLiquidInfo();

	cout << "���̒ǉ�" << endl;
	pWater = LiquidOperation::createWater();
	pPot->pourLiquid( pWater );
	pPot->showLiquidInfo();

	cout << "�ĉ��M" << endl;
	timer.start( SEC_50 );
	pPot->showLiquidInfo();

	// �֌����J��
	pPot->turnTabOn();
	timer.start( SEC_30 );
	pPot->showLiquidInfo();

	// �֌������
	pPot->turnTabOff();
	timer.start( SEC_10 );
	pPot->showLiquidInfo();

	// �q�[�^�[�̃X�C�b�`�؂�
	pPot->turnHeaterOff();

	cout << ">���R��p��" << endl;
	timer.start( SEC_20 );
	pPot->showLiquidInfo();

	delete( pPot );
}

