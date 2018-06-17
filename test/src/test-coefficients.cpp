#include "Common.h"

/**
 * всюду сходящийся ряд, расчет b_n_k
 * Формулы Эйлера-Маклорена(формула трапеций), равномерная сетка
 */
namespace {
    // Подынтегральная функция
    BmpReal f(size_t n, const BmpReal& tau) {
        BmpReal mul = pow(1 - 2*exp(-tau*tau), n);
        return mul*exp(-tau*tau);
    }

    // Формула трапеций
    BmpReal trapz(size_t n, const BmpReal& P) {
        BmpReal F = 0;
        BmpReal h = 8.0 / P;
        for (size_t p = P - 1; p > 0; --p) {
            F += f(n, 8*p/P);
        }
        return (2*F + pow(-1, n))*h;
    }

    // Вычисление коэффициентов по методу, близкому к Ричардсону(сверхстепенная сходимость)
    BmpReal calculateBm12(size_t N) {
        BmpReal k = -0.5;
        BmpReal P0 = 8.0;
        BmpReal I2n, In, stopCriteria;
        do {
            In = trapz(N, P0);
            I2n = trapz(N, 2 * P0);
            P0 *= 2;
            stopCriteria = abs(I2n - In);
        } while (stopCriteria > 1e-14);
        return I2n / fdsf::factorial(k);
    }

    // Вычисление для индекса k = 0
    BmpVector calculateK0(size_t N) {
        BmpVector B0;
        for (size_t i = 0; i <= N; ++i) {
            BmpReal value = (1 + pow(-1.0, i))/(2*(i+1));
            B0.push_back(value);
        }
        return B0;
    }

    // Вычисление по реккурентной формуле
    BmpVector calculateBk(const BmpVector& Bkm1) {
        BmpVector Bk;
        size_t N = Bkm1.size();
        BmpReal value = 0;
        for (size_t i = 0; i < N; ++i) {
            value += Bkm1.at(i);
            Bk.push_back(value / (i + 1));
        }
        return Bk;
    }
}

TEST_CASE("mHalf") {
    BmpVector bm12;
    for (size_t N = 0; N <= 67; ++N) {
        bm12.push_back(calculateBm12(N));
    }
    filesys::writeFile("bm12.txt", bm12);
}

TEST_CASE("half") {
    const BmpVector B_m12 = {
        1.0000000000000000,
       -0.41421356237309515,
        0.48097395201231308,
       -0.31443745684377605,
        0.35496973905796525,
       -0.2639146991274261,
        0.29305220065772453,
       -0.23206012422784597,
        0.25480909731988405,
       -0.20961507725316636,
        0.22827198241767724,
       -0.19269402581588935,
        0.20850412514677033,
       -0.17934271566143664,
        0.19305732762114028,
       -0.16845640223916253,
        0.1805638658684417 ,
       -0.15935707527675091,
        0.17019275877281642,
       -0.15160238383284011,
        0.16140657992677773,
       -0.14488973151960657,
        0.15384051431503362,
       -0.13900414944762135,
        0.1472371586201546 ,
       -0.13378812964569098,
        0.14140906612540924,
       -0.12912325802251828,
        0.13621609350926644,
       -0.12491855193815647,
        0.13155110392581695,
       -0.12110278860777168,
        0.12733061461119022,
       -0.11761930413804721,
        0.12348848883008756,
       -0.11442237441589655,
        0.11997156715133331,
       -0.11147463877385461,
        0.11673657115056887,
       -0.10874522884795892,
        0.11374786384105723,
       -0.10620838520960593,
        0.11097580026521373,
       -0.10384241822419096,
        0.10839549296611649,
       -0.10162891623985279,
        0.10598587447494355,
       -0.09955213438673234,
        0.10372897595078695,
       -0.09759851721451281,
        0.10160936547917465,
       -0.09575632184163210,
        0.099613705906352476,
       -0.09401531751504925,
        0.097730403282552378,
        -0.09236654391281224,
        0.095949324771059719,
        -0.09080211507512911,
        0.094261570372856804,
        -0.08931505911688105,
        0.092659286746943334,
        -0.08789918624863347,
        0.091135514254736275,
        -0.08654897937862024,
        0.089684060445614291,
        -0.08525950286539473,
        0.088299394749181859,
        -0.08402632596474541,
    };

    BmpVector b12 = calculateBk(B_m12);
    filesys::writeFile("b12.txt", b12);
}

TEST_CASE("3/2") {
    const BmpVector B12 = {
        1.00000000000000000,
        0.29289321881345243,
        0.35558679654640596,
        0.18808073319886048,
        0.22145853437068147,
        0.14056299545433018,
        0.16234716762624365,
        0.11304625614448247,
        0.12879768294174931,
        0.09495640692225774,
        0.10707600469456860,
        0.08209516881869711,
        0.09181893469008735,
        0.07245024537926421,
        0.08049071752872261,
        0.06493152254322979,
        0.07173342509177166,
        0.05889506396018707,
        0.06475283737137809,
        0.05393507631116717,
        0.05905276695952958,
        0.04978265339229612,
        0.05430690821502384,
        0.04625228081241362,
        0.05029167592472326,
        0.04321168340278425,
        0.04684862350362221,
        0.04056391344911719,
        0.04386226448567407,
        0.03823623727154638,
        0.04124639426039382,
        0.03617298229576366,
        0.03893533479017052,
        0.03433078658639941,
        0.03687814950764765,
        0.03267535717643808,
        0.03503471420278660,
        0.03117920491392763,
        0.03337298353537996,
        0.02982002822579649,
        0.03186704860665650,
        0.02857953827769788,
        0.03049573041694243,
        0.02744259067509849,
        0.02924154405934333,
        0.02639653405283907,
        0.02808992427458597,
        0.02543071471914185,
        0.02702863841774685,
        0.02453609530510165,
        0.02604733589675014,
        0.02370495786331971,
        0.02513719839243354,
        0.02293067032007274,
        0.02429066546484510,
        0.02220750101167265,
        0.02350121721797768,
        0.02153047010947584,
        0.02276320062241450,
        0.02089522962675958,
        0.02207168957954948,
        0.02029796577586911,
        0.02142237130727970,
        0.01973531895281251,
        0.02081145343731716,
        0.01920431773576092,
        0.02023558754193138,
        0.01870232410800966,
    };

    BmpVector b32 = calculateBk(B12);
    filesys::writeFile("b32.txt", b32);
}

TEST_CASE("5/2") {
    const BmpVector B32 = {
        1.00000000000000000,
        0.64644660940672627,
        0.54949333845328618,
        0.45914018713967975,
        0.41160385658588011,
        0.36643037973062181,
        0.33727563514428205,
        0.30924696276930708,
        0.28919704278846736,
        0.26977297920184640,
        0.25498234515573021,
        0.24057508046097745,
        0.22913230001706283,
        0.21794072468579154,
        0.20877739087532027,
        0.19978702410456461,
        0.19225445945675326,
        0.18484560415138848,
        0.17852493221559845,
        0.17229543942037689,
        0.16690293120795557,
        0.16157928221633469,
        0.15691526595540814,
        0.15230430824111671,
        0.14822380294846099,
        0.14418487527362728,
        0.14057982891177523,
        0.13700783193096602,
        0.13379591581216285,
        0.13061059319414231,
        0.12772787709950525,
        0.12486678663688833,
        0.12226280324759384,
        0.11967656746344106,
        0.11731089837898982,
        0.11495991112336339,
        0.11279977066605049,
        0.11065186104099461,
        0.10867035136136348,
        0.10669909328297431,
        0.10487392146160071,
        0.10305738852865064,
        0.10136990810744811,
        0.09968974180216744,
        0.09812422629677135,
        0.09656492863929457,
        0.09510801365281142,
        0.09365640325835996,
        0.09229665295549030,
        0.09094144180248254,
        0.08966900835335054,
        0.08840046892084995,
        0.08720682230710623,
        0.08601652319623525,
        0.08489423487384633,
        0.08377482891202180,
        0.08271739712791576,
        0.08166245011035646,
        0.08066415774615404,
        0.07966800894416413,
        0.07872380698736717,
        0.07778145470976236,
        0.07688686608432613,
        0.07599387316039623,
        0.07514491285696424,
        0.07429732808240055,
        0.07349043643254280,
        0.07268472889835849,
    };

    BmpVector b52 = calculateBk(B32);
    filesys::writeFile("b52.txt", b52);
}

TEST_CASE("7/2") {
    const BmpVector B52 = {
        1.00000000000000000,
        0.82322330470336313,
        0.73197998262000408,
        0.66377003374992305,
        0.61333679831711441,
        0.57218572855269900,
        0.53862714378006804,
        0.50995462115372292,
        0.48542600133536123,
        0.46386069912200972,
        0.44487175785234795,
        0.42784703473640034,
        0.41256128591183594,
        0.39865981725283278,
        0.38600098882766526,
        0.37436261603247145,
        0.36365037152801749,
        0.35371677334042695,
        0.34449615012333074,
        0.33588611458818302,
        0.32783929633198172,
        0.32028202296308866,
        0.31317912048449387,
        0.30647600330768648,
        0.30014591529331747,
        0.29414741375409864,
        0.28845972542660520,
        0.28305072923033237,
        0.27790401152625754,
        0.27299423091518704,
        0.26830821950177797,
        0.26382567472475016,
        0.25953589074059391,
        0.25542238123244237,
        0.25147633886520088,
        0.24768421587237210,
        0.24403869032625530,
        0.24052851060822211,
        0.23714753216599496,
        0.23388632119391944,
        0.23073967729800923,
        0.22769962280350070,
        0.22476172246173204,
        0.22191917744674194,
        0.21916817853229817,
        0.21650289049114591,
        0.21392002077118136,
        0.21141452873966424,
        0.20898355168284435,
        0.20662270948523712,
        0.20432949965912170,
        0.20210009522184727,
        0.19993229761968234,
        0.19782274624147037,
        0.19576950058024084,
        0.19376959572902264,
        0.19182131154303830,
        0.18992202082868170,
        0.18807019264084227,
        0.18626348957923095,
        0.18450054396297091,
        0.18277926832985464,
        0.18109843654817959,
        0.17945617774524547,
        0.17785138905465653,
        0.17628238813083447,
        0.17474817989653160,
        0.17324724679361730,
    };

    BmpVector b72 = calculateBk(B52);
    filesys::writeFile("b72.txt", b72);
}

TEST_CASE("k0") {
    size_t N = 67;
    BmpVector b0 = calculateK0(N);
    filesys::writeFile("b0.txt", b0);
}

TEST_CASE("k1") {
    const BmpVector BK0 = {
        1.00000000000000000,
        0.00000000000000000,
        0.33333333333333331,
        0.00000000000000000,
        0.20000000000000001,
        0.00000000000000000,
        0.14285714285714285,
        0.00000000000000000,
        0.11111111111111110,
        0.00000000000000000,
        0.09090909090909091,
        0.00000000000000000,
        0.07692307692307693,
        0.00000000000000000,
        0.06666666666666667,
        0.00000000000000000,
        0.05882352941176471,
        0.00000000000000000,
        0.05263157894736842,
        0.00000000000000000,
        0.04761904761904762,
        0.00000000000000000,
        0.04347826086956522,
        0.00000000000000000,
        0.04000000000000000,
        0.00000000000000000,
        0.03703703703703703,
        0.00000000000000000,
        0.03448275862068965,
        0.00000000000000000,
        0.03225806451612903,
        0.00000000000000000,
        0.03030303030303030,
        0.00000000000000000,
        0.02857142857142857,
        0.00000000000000000,
        0.02702702702702703,
        0.00000000000000000,
        0.02564102564102564,
        0.00000000000000000,
        0.02439024390243903,
        0.00000000000000000,
        0.02325581395348837,
        0.00000000000000000,
        0.02222222222222222,
        0.00000000000000000,
        0.02127659574468085,
        0.00000000000000000,
        0.02040816326530612,
        0.00000000000000000,
        0.01960784313725490,
        0.00000000000000000,
        0.01886792452830189,
        0.00000000000000000,
        0.01818181818181818,
        0.00000000000000000,
        0.01754385964912281,
        0.00000000000000000,
        0.01694915254237288,
        0.00000000000000000,
        0.01639344262295082,
        0.00000000000000000,
        0.01587301587301587,
        0.00000000000000000,
        0.01538461538461539,
        0.00000000000000000,
        0.01492537313432836,
        0.00000000000000000,
    };
    BmpVector bk1 = calculateBk(BK0);
    filesys::writeFile("b1.txt", bk1);
}

TEST_CASE("k2") {
    const BmpVector BK1 = {
        1.00000000000000000,
        0.50000000000000000,
        0.44444444444444442,
        0.33333333333333331,
        0.30666666666666664,
        0.25555555555555554,
        0.23945578231292514,
        0.20952380952380950,
        0.19858906525573192,
        0.17873015873015871,
        0.17074642529187981,
        0.15651755651755650,
        0.15039490424105806,
        0.13965241108098250,
        0.13478669478669478,
        0.12636252636252635,
        0.12238964418895212,
        0.11559021951178811,
        0.11227660685050288,
        0.10666277650797773,
        0.10385117037040963,
        0.09913066262630009,
        0.09671099298470294,
        0.09268136827700697,
        0.09057411354592670,
        0.08709049379416028,
        0.08523666206241499,
        0.08219249556018589,
        0.08054733221744463,
        0.07786242114352980,
        0.07639131286522656,
        0.07400408433818823,
        0.07267980997348647,
        0.07054216850367805,
        0.06934300450561377,
        0.06741680993601339,
        0.06632519418171647,
        0.06457979433482919,
        0.06358136436832140,
        0.06199183025911337,
        0.06107471839675545,
        0.05962055843492794,
        0.05877486670280144,
        0.05743907427773778,
        0.05665647756539299,
        0.05542481500962358,
        0.05469825715292267,
        0.05355871012890345,
        0.05288216835617696,
        0.05182452498905343,
        0.05119282534490051,
        0.05020834793442165,
        0.04961701919090997,
        0.04869818550218941,
        0.04814334246000084,
        0.04728363991607226,
        0.04676188938507314,
        0.04595564991291671,
        0.04546401436426342,
        0.04470628079152570,
        0.04424213590351627,
        0.04352855306636278,
        0.04308957628551600,
        0.04241630165605482,
        0.04200042955957113,
        0.04136405941472915,
        0.04096945215681271,
        0.04036696021333017,
    };
    BmpVector bk2 = calculateBk(BK1);
    filesys::writeFile("bk2.txt", bk2);
}

TEST_CASE("k3") {
    const BmpVector BK2 = {
        1.00000000000000000,
        0.75000000000000000,
        0.64814814814814814,
        0.56944444444444442,
        0.51688888888888884,
        0.47333333333333333,
        0.43992225461613216,
        0.41112244897959183,
        0.38750762856582965,
        0.36662988158226251,
        0.34882229464677317,
        0.33279689980267180,
        0.31876597706716309,
        0.30597215092529301,
        0.29455978718271980,
        0.28404745838145773,
        0.27453817519366330,
        0.26570773321133689,
        0.25763241077129301,
        0.25008392905812726,
        0.24312046435871212,
        0.23657547337087523,
        0.23049440900625906,
        0.22475219897587354,
        0.21938507555867567,
        0.21429682241388662,
        0.20951681647494322,
        0.20496951929941615,
        0.20067909905521025,
        0.19658520979148755,
        0.19270798730999525,
        0.18899849034212629,
        0.18547368184610691,
        0.18209334321838841,
        0.17887190496945199,
        0.17577593010741202,
        0.17281780210942027,
        0.16996943348377314,
        0.16724153427568461,
        0.16461029167527036,
        0.16208503379042852,
        0.15964540342482136,
        0.15729957698942557,
        0.15503002010961447,
        0.15284394138640955,
        0.15072613429126203,
        0.14868298796916971,
        0.14670123218083084,
        0.14478655740889912,
        0.14292731676050219,
        0.14112860124254922,
        0.13938013483277753,
        0.13768649114142154,
        0.13603855955550984,
        0.13444046469922785,
        0.13288409282810007,
        0.13137317697822240,
        0.12990046099433783,
        0.12846933478026876,
        0.12707328388045638,
        0.12571539620870326,
        0.12438980196447197,
        0.12309932219179014,
        0.12183864999591927,
        0.12061036968151391,
        0.11940966801080505,
        0.11823891852044695,
        0.11709374266298934,
    };

    BmpVector bk3 = calculateBk(BK2);
    filesys::writeFile("bk3.txt", bk3);
}

TEST_CASE("k4") {
    const BmpVector BK3 = {
        1.00000000000000000,
        0.87500000000000000,
        0.79938271604938260,
        0.74189814814814814,
        0.69689629629629635,
        0.65963580246913578,
        0.62824815277584956,
        0.60110743980131731,
        0.57737412744181871,
        0.55629970285586317,
        0.53743812029140037,
        0.52038468525067294,
        0.50487555385194149,
        0.49066816792860946,
        0.47759427587888342,
        0.46549759978529431,
        0.45426469245637480,
        0.44378930583165049,
        0.43399157451268427,
        0.42479619223995640,
        0.41614496710275428,
        0.40798271738766889,
        0.40026583441456409,
        0.39295276627128528,
        0.38601005864278087,
        0.37940570340320801,
        0.37311352240586487,
        0.36710837943777747,
        0.36136943873493027,
        0.35587663110348217,
        0.35061312646498266,
        0.34556266908614336,
        0.34071148765462711,
        0.33604624811238482,
        0.33155555259401526,
        0.32722834085827629,
        0.32305508305425318,
        0.31902651332871423,
        0.31513459078889294,
        0.31137148331105235,
        0.30773035039591523,
        0.30420451832517487,
        0.30078812434062258,
        0.29747544015355420,
        0.29426140684761770,
        0.29114107483552298,
        0.28811005171070697,
        0.28516403463716788,
        0.28229918816312161,
        0.27951175073506923,
        0.27679835564698058,
        0.27415569755439972,
        0.27158080686736241,
        0.26907076525047624,
        0.26662294160408995,
        0.26423474787594725,
        0.26190384312335557,
        0.25962792274182078,
        0.25740489582721821,
        0.25523270229477218,
        0.25310946776877102,
        0.25103334412676620,
        0.24900264536589356,
        0.24701570793823771,
        0.24507101042659579,
        0.24316705069302325,
        0.24130245170537284,
        0.23947585304298483,
    };

    BmpVector bk4 = calculateBk(BK3);
    filesys::writeFile("bk4.txt", bk4);
}
