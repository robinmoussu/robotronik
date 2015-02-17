#include "asser.h"

unsigned int tabSin[NB_SIN] = {0, 40, 81, 122, 162, 203, 244, 284, 325, 366, 406, 447, 488, 528, 569, 610, 650, 691, 732, 772, 813, 854, 894, 935, 976, 1016, 1057, 1098, 1138, 1179, 1220, 1260, 1301, 1342, 1382, 1423, 1464, 1504, 1545, 1586, 1626, 1667, 1707, 1748, 1789, 1829, 1870, 1911, 1951, 1992, 2033, 2073, 2114, 2154, 2195, 2236, 2276, 2317, 2358, 2398, 2439, 2479, 2520, 2561, 2601, 2642, 2682, 2723, 2764, 2804, 2845, 2885, 2926, 2967, 3007, 3048, 3088, 3129, 3169, 3210, 3251, 3291, 3332, 3372, 3413, 3453, 3494, 3534, 3575, 3616, 3656, 3697, 3737, 3778, 3818, 3859, 3899, 3940, 3980, 4021, 4061, 4102, 4142, 4183, 4223, 4264, 4304, 4345, 4385, 4426, 4466, 4507, 4547, 4587, 4628, 4668, 4709, 4749, 4790, 4830, 4871, 4911, 4951, 4992, 5032, 5073, 5113, 5153, 5194, 5234, 5275, 5315, 5355, 5396, 5436, 5476, 5517, 5557, 5597, 5638, 5678, 5718, 5759, 5799, 5839, 5880, 5920, 5960, 6001, 6041, 6081, 6122, 6162, 6202, 6242, 6283, 6323, 6363, 6403, 6444, 6484, 6524, 6564, 6604, 6645, 6685, 6725, 6765, 6805, 6846, 
6886, 6926, 6966, 7006, 7046, 7087, 7127, 7167, 7207, 7247, 7287, 7327, 7367, 7408, 7448, 7488, 7528, 7568, 7608, 7648, 7688, 7728, 7768, 7808, 7848, 7888, 7928, 7968, 8008, 8048, 8088, 8128, 8168, 8208, 8248, 8288, 8328, 8368, 8408, 8448, 8488, 8527, 8567, 8607, 8647, 8687, 8727, 8767, 8807, 8846, 8886, 8926, 8966, 9006, 9046, 9085, 9125, 9165, 9205, 9244, 9284, 9324, 9364, 9403, 9443, 9483, 9523, 9562, 9602, 9642, 9681, 9721, 9761, 9800, 9840, 9880, 9919, 9959, 9998, 10038, 10078, 10117, 10157, 10196, 10236, 10275, 10315, 10354, 10394, 10434, 10473, 10513, 10552, 10591, 10631, 10670, 10710, 10749, 10789, 10828, 10868, 10907, 10946, 10986, 11025, 11064, 11104, 11143, 11183, 11222, 11261, 11300, 11340, 11379, 11418, 11458, 11497, 11536, 11575, 11615, 11654, 11693, 11732, 11771, 11811, 11850, 11889, 11928, 11967, 12006, 12045, 12084, 12124, 12163, 12202, 12241, 12280, 12319, 12358, 12397, 12436, 12475, 12514, 12553, 12592, 12631, 12670, 12709, 12748, 12787, 12825, 12864, 12903, 12942, 12981, 13020, 13059, 
13097, 13136, 13175, 13214, 13253, 13291, 13330, 13369, 13408, 13446, 13485, 13524, 13562, 13601, 13640, 13678, 13717, 13756, 13794, 13833, 13872, 13910, 13949, 13987, 14026, 14064, 14103, 14141, 14180, 14218, 14257, 14295, 14334, 14372, 14411, 14449, 14487, 14526, 14564, 14603, 14641, 14679, 14718, 14756, 14794, 14832, 14871, 14909, 14947, 14985, 15024, 15062, 15100, 15138, 15176, 15215, 15253, 15291, 15329, 15367, 15405, 15443, 15481, 15519, 15557, 15595, 15633, 15671, 15709, 15747, 15785, 15823, 15861, 15899, 15937, 15975, 16013, 16051, 16088, 16126, 16164, 16202, 16240, 16277, 16315, 16353, 16391, 16428, 16466, 16504, 16541, 16579, 16617, 16654, 16692, 16730, 16767, 16805, 16842, 16880, 16917, 16955, 16992, 17030, 17067, 17105, 17142, 17180, 17217, 17255, 17292, 17329, 17367, 17404, 17441, 17479, 17516, 17553, 17591, 17628, 17665, 17702, 17739, 17777, 17814, 17851, 17888, 17925, 17962, 17999, 18037, 18074, 18111, 18148, 18185, 18222, 18259, 18296, 18333, 18370, 18407, 18443, 18480, 18517, 18554, 18591, 
18628, 18665, 18701, 18738, 18775, 18812, 18848, 18885, 18922, 18958, 18995, 19032, 19068, 19105, 19142, 19178, 19215, 19251, 19288, 19324, 19361, 19397, 19434, 19470, 19507, 19543, 19580, 19616, 19652, 19689, 19725, 19761, 19798, 19834, 19870, 19906, 19943, 19979, 20015, 20051, 20087, 20124, 20160, 20196, 20232, 20268, 20304, 20340, 20376, 20412, 20448, 20484, 20520, 20556, 20592, 20628, 20664, 20700, 20735, 20771, 20807, 20843, 20879, 20914, 20950, 20986, 21022, 21057, 21093, 21129, 21164, 21200, 21235, 21271, 21307, 21342, 21378, 21413, 21449, 21484, 21519, 21555, 21590, 21626, 21661, 21696, 21732, 21767, 21802, 21838, 21873, 21908, 21943, 21979, 22014, 22049, 22084, 22119, 22154, 22189, 22225, 22260, 22295, 22330, 22365, 22400, 22435, 22470, 22504, 22539, 22574, 22609, 22644, 22679, 22714, 22748, 22783, 22818, 22853, 22887, 22922, 22957, 22991, 23026, 23060, 23095, 23130, 23164, 23199, 23233, 23268, 23302, 23337, 23371, 23405, 23440, 23474, 23509, 23543, 23577, 23611, 23646, 23680, 23714, 23748, 23783, 
23817, 23851, 23885, 23919, 23953, 23987, 24021, 24055, 24089, 24123, 24157, 24191, 24225, 24259, 24293, 24327, 24360, 24394, 24428, 24462, 24496, 24529, 24563, 24597, 24630, 24664, 24698, 24731, 24765, 24798, 24832, 24865, 24899, 24932, 24966, 24999, 25033, 25066, 25099, 25133, 25166, 25199, 25233, 25266, 25299, 25332, 25365, 25399, 25432, 25465, 25498, 25531, 25564, 25597, 25630, 25663, 25696, 25729, 25762, 25795, 25828, 25861, 25894, 25926, 25959, 25992, 26025, 26057, 26090, 26123, 26155, 26188, 26221, 26253, 26286, 26318, 26351, 26383, 26416, 26448, 26481, 26513, 26545, 26578, 26610, 26643, 26675, 26707, 26739, 26772, 26804, 26836, 26868, 26900, 26932, 26964, 26996, 27029, 27061, 27093, 27124, 27156, 27188, 27220, 27252, 27284, 27316, 27348, 27379, 27411, 27443, 27475, 27506, 27538, 27570, 27601, 27633, 27664, 27696, 27727, 27759, 27790, 27822, 27853, 27885, 27916, 27947, 27979, 28010, 28041, 28073, 28104, 28135, 28166, 28197, 28228, 28260, 28291, 28322, 28353, 28384, 28415, 28446, 28477, 28508, 28538, 
28569, 28600, 28631, 28662, 28693, 28723, 28754, 28785, 28815, 28846, 28877, 28907, 28938, 28968, 28999, 29029, 29060, 29090, 29121, 29151, 29181, 29212, 29242, 29272, 29303, 29333, 29363, 29393, 29424, 29454, 29484, 29514, 29544, 29574, 29604, 29634, 29664, 29694, 29724, 29754, 29784, 29813, 29843, 29873, 29903, 29933, 29962, 29992, 30022, 30051, 30081, 30110, 30140, 30169, 30199, 30228, 30258, 30287, 30317, 30346, 30375, 30405, 30434, 30463, 30493, 30522, 30551, 30580, 30609, 30638, 30667, 30696, 30726, 30755, 30783, 30812, 30841, 30870, 30899, 30928, 30957, 30986, 31014, 31043, 31072, 31100, 31129, 31158, 31186, 31215, 31243, 31272, 31301, 31329, 31357, 31386, 31414, 31443, 31471, 31499, 31528, 31556, 31584, 31612, 31640, 31669, 31697, 31725, 31753, 31781, 31809, 31837, 31865, 31893, 31921, 31948, 31976, 32004, 32032, 32060, 32087, 32115, 32143, 32170, 32198, 32226, 32253, 32281, 32308, 32336, 32363, 32391, 32418, 32445, 32473, 32500, 32527, 32555, 32582, 32609, 32636, 32663, 32690, 32718, 32745, 32772, 
32799, 32826, 32853, 32880, 32906, 32933, 32960, 32987, 33014, 33040, 33067, 33094, 33121, 33147, 33174, 33200, 33227, 33253, 33280, 33306, 33333, 33359, 33386, 33412, 33438, 33465, 33491, 33517, 33543, 33569, 33596, 33622, 33648, 33674, 33700, 33726, 33752, 33778, 33804, 33830, 33856, 33881, 33907, 33933, 33959, 33984, 34010, 34036, 34061, 34087, 34113, 34138, 34164, 34189, 34214, 34240, 34265, 34291, 34316, 34341, 34367, 34392, 34417, 34442, 34467, 34492, 34518, 34543, 34568, 34593, 34618, 34643, 34668, 34692, 34717, 34742, 34767, 34792, 34816, 34841, 34866, 34890, 34915, 34940, 34964, 34989, 35013, 35038, 35062, 35087, 35111, 35135, 35160, 35184, 35208, 35232, 35257, 35281, 35305, 35329, 35353, 35377, 35401, 35425, 35449, 35473, 35497, 35521, 35544, 35568, 35592, 35616, 35639, 35663, 35687, 35710, 35734, 35758, 35781, 35805, 35828, 35851, 35875, 35898, 35922, 35945, 35968, 35991, 36015, 36038, 36061, 36084, 36107, 36130, 36153, 36176, 36199, 36222, 36245, 36268, 36291, 36314, 36336, 36359, 36382, 36404, 
36427, 36450, 36472, 36495, 36517, 36540, 36562, 36585, 36607, 36630, 36652, 36674, 36696, 36719, 36741, 36763, 36785, 36807, 36829, 36852, 36874, 36896, 36917, 36939, 36961, 36983, 37005, 37027, 37049, 37070, 37092, 37114, 37135, 37157, 37178, 37200, 37222, 37243, 37264, 37286, 37307, 37329, 37350, 37371, 37392, 37414, 37435, 37456, 37477, 37498, 37519, 37540, 37561, 37582, 37603, 37624, 37645, 37666, 37687, 37707, 37728, 37749, 37770, 37790, 37811, 37831, 37852, 37872, 37893, 37913, 37934, 37954, 37974, 37995, 38015, 38035, 38056, 38076, 38096, 38116, 38136, 38156, 38176, 38196, 38216, 38236, 38256, 38276, 38296, 38315, 38335, 38355, 38374, 38394, 38414, 38433, 38453, 38472, 38492, 38511, 38531, 38550, 38570, 38589, 38608, 38627, 38647, 38666, 38685, 38704, 38723, 38742, 38761, 38780, 38799, 38818, 38837, 38856, 38875, 38894, 38912, 38931, 38950, 38968, 38987, 39006, 39024, 39043, 39061, 39080, 39098, 39116, 39135, 39153, 39171, 39190, 39208, 39226, 39244, 39262, 39280, 39298, 39316, 39334, 39352, 39370, 
39388, 39406, 39424, 39442, 39459, 39477, 39495, 39512, 39530, 39548, 39565, 39583, 39600, 39618, 39635, 39652, 39670, 39687, 39704, 39722, 39739, 39756, 39773, 39790, 39807, 39824, 39841, 39858, 39875, 39892, 39909, 39926, 39942, 39959, 39976, 39993, 40009, 40026, 40042, 40059, 40076, 40092, 40108, 40125, 40141, 40158, 40174, 40190, 40206, 40223, 40239, 40255, 40271, 40287, 40303, 40319, 40335, 40351, 40367, 40383, 40399, 40414, 40430, 40446, 40462, 40477, 40493, 40508, 40524, 40539, 40555, 40570, 40586, 40601, 40616, 40632, 40647, 40662, 40677, 40693, 40708, 40723, 40738, 40753, 40768, 40783, 40798, 40813, 40827, 40842, 40857, 40872, 40886, 40901, 40916, 40930, 40945, 40959, 40974, 40988, 41003, 41017, 41032, 41046, 41060, 41074, 41089, 41103, 41117, 41131, 41145, 41159, 41173, 41187, 41201, 41215, 41229, 41243, 41256, 41270, 41284, 41297, 41311, 41325, 41338, 41352, 41365, 41379, 41392, 41406, 41419, 41432, 41446, 41459, 41472, 41485, 41498, 41511, 41525, 41538, 41551, 41564, 41576, 41589, 41602, 41615, 
41628, 41641, 41653, 41666, 41679, 41691, 41704, 41716, 41729, 41741, 41754, 41766, 41778, 41791, 41803, 41815, 41827, 41840, 41852, 41864, 41876, 41888, 41900, 41912, 41924, 41936, 41948, 41959, 41971, 41983, 41995, 42006, 42018, 42030, 42041, 42053, 42064, 42076, 42087, 42098, 42110, 42121, 42132, 42143, 42155, 42166, 42177, 42188, 42199, 42210, 42221, 42232, 42243, 42254, 42265, 42275, 42286, 42297, 42308, 42318, 42329, 42340, 42350, 42361, 42371, 42381, 42392, 42402, 42413, 42423, 42433, 42443, 42453, 42464, 42474, 42484, 42494, 42504, 42514, 42524, 42534, 42543, 42553, 42563, 42573, 42582, 42592, 42602, 42611, 42621, 42630, 42640, 42649, 42659, 42668, 42677, 42687, 42696, 42705, 42714, 42724, 42733, 42742, 42751, 42760, 42769, 42778, 42787, 42796, 42804, 42813, 42822, 42831, 42839, 42848, 42856, 42865, 42874, 42882, 42891, 42899, 42907, 42916, 42924, 42932, 42940, 42949, 42957, 42965, 42973, 42981, 42989, 42997, 43005, 43013, 43021, 43029, 43036, 43044, 43052, 43059, 43067, 43075, 43082, 43090, 43097, 
43105, 43112, 43120, 43127, 43134, 43141, 43149, 43156, 43163, 43170, 43177, 43184, 43191, 43198, 43205, 43212, 43219, 43226, 43233, 43239, 43246, 43253, 43259, 43266, 43272, 43279, 43285, 43292, 43298, 43305, 43311, 43317, 43324, 43330, 43336, 43342, 43348, 43354, 43360, 43366, 43372, 43378, 43384, 43390, 43396, 43402, 43407, 43413, 43419, 43424, 43430, 43436, 43441, 43447, 43452, 43457, 43463, 43468, 43473, 43479, 43484, 43489, 43494, 43499, 43504, 43509, 43514, 43519, 43524, 43529, 43534, 43539, 43544, 43548, 43553, 43558, 43562, 43567, 43571, 43576, 43580, 43585, 43589, 43593, 43598, 43602, 43606, 43611, 43615, 43619, 43623, 43627, 43631, 43635, 43639, 43643, 43647, 43651, 43654, 43658, 43662, 43665, 43669, 43673, 43676, 43680, 43683, 43687, 43690, 43694, 43697, 43700, 43703, 43707, 43710, 43713, 43716, 43719, 43722, 43725, 43728, 43731, 43734, 43737, 43740, 43742, 43745, 43748, 43751, 43753, 43756, 43758, 43761, 43763, 43766, 43768, 43771, 43773, 43775, 43777, 43780, 43782, 43784, 43786, 43788, 43790, 
43792, 43794, 43796, 43798, 43800, 43801, 43803, 43805, 43807, 43808, 43810, 43811, 43813, 43814, 43816, 43817, 43819, 43820, 43821, 43823, 43824, 43825, 43826, 43827, 43828, 43829, 43830, 43831, 43832, 43833, 43834, 43835, 43836, 43836, 43837, 43838, 43838, 43839, 43840, 43840, 43841, 43841, 43841, 43842, 43842, 43842, 43843, 43843, 43843, 43843, 43843, 43843, 43843};

long myCos(unsigned int in) {
	unsigned int tmp = in % NB_SIN;
	switch (in / NB_SIN) {
	case 0: // 0, 90
		return -(long)tabSin[NB_SIN - tmp - 1] << 2;
	case 1: // 90, 180
		return (long)tabSin[tmp] << 2;
	case 2: // 180, 270
		return (long)tabSin[NB_SIN - tmp - 1] << 2;
	default: // 270, 360
		return -(long)tabSin[tmp] << 2;
	}
}

long mySin(unsigned int in) {
	unsigned int tmp = in % NB_SIN;
	switch (in / NB_SIN) {
	case 0: // 0, 90
		return (long)tabSin[tmp] << 2;
	case 1: // 90, 180
		return (long)tabSin[NB_SIN - tmp - 1] << 2;
	case 2: // 180, 270
		return -(long)tabSin[tmp] << 2;
	default: // 270, 360
		return -(long)tabSin[NB_SIN - tmp - 1] << 2;
	}
}
