#pragma once
#ifndef GLOBALENUMS_H
#define GLOBALENUMS_H


enum elements
{
	Neutral = 0,
	Fire,
	Water,
	Air,
	Earth
};

enum abilityName
{
	Fireball = 0,
	Bubble,
	WindBlow,
	EarthArmor,
	Barrier,
	Heal,
	Restore,
	EarthBarrier,
	WindBarrier,
	WaterBarrier,
	FireBarrier,
	Mirror,
	Tsunami,
	FireTornado,
	HotVampire,
	Earthquake,
	Geiser,
	PoisonGas,
	MagmaWave,
	Inferno,
	Swirl,
	SabakuKyu,
	Doton,
	Test,
	CraftError
};

enum positiveStates
{
	increasePD = 0,
	increaseMR,
	increaseMD,
	heal,
	restore,
	doton,
	waterResist,
	fireResist,
	airResist,
	earthResist,
	damageMultiplier,
	trueDamage
};

enum negativeStates
{
	vampireishon = 0,
	stun,
	burns,
	poison,
	reducePD,
	reduceMR,
	reduceAtt,
};

enum turns
{
	start = 0,
	check,
	wait,
	attack,
	ability1,
	ability2,
	ability3,
	enemyUpdateText,
	enemyCheck,
	enemyWait,
	enemyAttack,
	enemyAbility1,
	enemyAbility2,
	updateText
};
#endif