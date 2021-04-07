#pragma once
#include <string>

const struct Res {
	const std::string name;
	const float density;
	const float resistance;
	Res(std::string name, float density, float resistance) : 
		name(name), density(density), resistance(resistance) {}
};

static const Res NRES_ = Res("NRES", 0.0f, 0.0f);
static const Res* NRES = &NRES_;
static const Res air_ = Res("air", 0.0f, 0.0f);
static const Res* air = &air_;
static const Res water_ = Res("water", 1.0f, 0.0f);
static const Res* water = &water_;
static const Res dirt_ = Res("dirt", 1.2f, 0.0f);
static const Res* dirt = &dirt_;
static const Res sand_ = Res("sand", 1.6f, 0.5f);
static const Res* sand = &sand_;
static const Res granite_ = Res("granite", 2.7f, 2.0f);
static const Res* granite = &granite_;
static const Res limestone_ = Res("limestone", 2.7f, 1.3f);
static const Res* limestone = &limestone_;
static const Res sandstone_ = Res("sandstone", 2.3f, 1.0f);
static const Res* sandstone = &sandstone_;
static const Res coal_ = Res("coal", 1.35f, 0.5f);
static const Res* coal = &coal_;
static const Res malachite_ = Res("malachite", 3.86f, 0.8f);
static const Res* malachite = &malachite_;
static const Res hematite_ = Res("hematite", 5.3f, 0.7f);
static const Res* hematite = &hematite_;
static const Res quartz_ = Res("quartz", 2.32f, 1.2f);
static const Res* quartz = &quartz_;
static const Res corundum_ = Res("corundum", 3.93f, 1.8f);
static const Res* corundum = &corundum_;

struct ResAmount
{
	const Res *res;
	float amount;
	ResAmount() : res(NRES), amount(0) {}
	ResAmount(const Res *res, float amount) : res(res), amount(amount) {}
};