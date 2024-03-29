﻿/*
 * VACityToProvince.cpp
 *
 *  Created on: 2013年9月11日
 *      Author: pffang
 */

#include "VAInc.h"

namespace VA {

struct __CityMap {
  char nProvince;
  const char* szCityName;
};

static const __CityMap CityList[] = { 
{ 1, "东城区" },
{ 1, "丰台区" },
{ 1, "大兴区" },
{ 1, "密云县" },
{ 1, "平谷区" },
{ 1, "延庆县" },
{ 1, "怀柔区" },
{ 1, "房山区" },
{ 1, "昌平区" },
{ 1, "朝阳区" },
{ 1, "海淀区" },
{ 1, "石景山区" },
{ 1, "西城区" },
{ 1, "通州区" },
{ 1, "门头沟区" },
{ 1, "顺义区" },
{ 2, "东丽区" },
{ 2, "北辰区" },
{ 2, "南开区" },
{ 2, "和平区" },
{ 2, "宁河县" },
{ 2, "宝坻区" },
{ 2, "武清区" },
{ 2, "河东区" },
{ 2, "河北区" },
{ 2, "河西区" },
{ 2, "津南区" },
{ 2, "滨海新区" },
{ 2, "红桥区" },
{ 2, "蓟县" },
{ 2, "西青区" },
{ 2, "静海县" },
{ 3, "嘉定区" },
{ 3, "奉贤区" },
{ 3, "宝山区" },
{ 3, "崇明县" },
{ 3, "徐汇区" },
{ 3, "普陀区" },
{ 3, "杨浦区" },
{ 3, "松江区" },
{ 3, "浦东新区" },
{ 3, "虹口区" },
{ 3, "金山区" },
{ 3, "长宁区" },
{ 3, "闵行区" },
{ 3, "闸北区" },
{ 3, "青浦区" },
{ 3, "静安区" },
{ 3, "黄浦区" },
{ 4, "万州区" },
{ 4, "丰都县" },
{ 4, "九龙坡区" },
{ 4, "云阳县" },
{ 4, "北碚区" },
{ 4, "南岸区" },
{ 4, "南川区" },
{ 4, "合川区" },
{ 4, "垫江县" },
{ 4, "城口县" },
{ 4, "大渡口区" },
{ 4, "大足区" },
{ 4, "奉节县" },
{ 4, "巫山县" },
{ 4, "巫溪县" },
{ 4, "巴南区" },
{ 4, "开县" },
{ 4, "彭水苗族土家族自治县" },
{ 4, "忠县" },
{ 4, "梁平县" },
{ 4, "武隆县" },
{ 4, "永川区" },
{ 4, "江北区" },
{ 4, "江津区" },
{ 4, "沙坪坝区" },
{ 4, "涪陵区" },
{ 4, "渝中区" },
{ 4, "渝北区" },
{ 4, "潼南县" },
{ 4, "璧山县" },
{ 4, "石柱土家族自治县" },
{ 4, "秀山土家族苗族自治县" },
{ 4, "綦江区" },
{ 4, "荣昌县" },
{ 4, "酉阳土家族苗族自治县" },
{ 4, "铜梁县" },
{ 4, "长寿区" },
{ 4, "黔江区" },
{ 5, "保定市" },
{ 5, "唐山市" },
{ 5, "廊坊市" },
{ 5, "张家口市" },
{ 5, "承德市" },
{ 5, "沧州市" },
{ 5, "石家庄市" },
{ 5, "秦皇岛市" },
{ 5, "衡水市" },
{ 5, "邢台市" },
{ 5, "邯郸市" },
{ 6, "临汾市" },
{ 6, "吕梁市" },
{ 6, "大同市" },
{ 6, "太原市" },
{ 6, "忻州市" },
{ 6, "晋中市" },
{ 6, "晋城市" },
{ 6, "朔州市" },
{ 6, "运城市" },
{ 6, "长治市" },
{ 6, "阳泉市" },
{ 7, "乌兰察布市" },
{ 7, "乌海市" },
{ 7, "兴安盟" },
{ 7, "包头市" },
{ 7, "呼伦贝尔市" },
{ 7, "呼和浩特市" },
{ 7, "巴彦淖尔市" },
{ 7, "赤峰市" },
{ 7, "通辽市" },
{ 7, "鄂尔多斯市" },
{ 7, "锡林郭勒盟" },
{ 7, "阿拉善盟" },
{ 8, "丹东市" },
{ 8, "大连市" },
{ 8, "抚顺市" },
{ 8, "朝阳市" },
{ 8, "本溪市" },
{ 8, "沈阳市" },
{ 8, "盘锦市" },
{ 8, "营口市" },
{ 8, "葫芦岛市" },
{ 8, "辽阳市" },
{ 8, "铁岭市" },
{ 8, "锦州市" },
{ 8, "阜新市" },
{ 8, "鞍山市" },
{ 9, "吉林市" },
{ 9, "四平市" },
{ 9, "延边朝鲜族自治州" },
{ 9, "松原市" },
{ 9, "白城市" },
{ 9, "白山市" },
{ 9, "辽源市" },
{ 9, "通化市" },
{ 9, "长春市" },
{ 10, "七台河市" },
{ 10, "伊春市" },
{ 10, "佳木斯市" },
{ 10, "双鸭山市" },
{ 10, "哈尔滨市" },
{ 10, "大兴安岭地区" },
{ 10, "大庆市" },
{ 10, "牡丹江市" },
{ 10, "绥化市" },
{ 10, "鸡西市" },
{ 10, "鹤岗市" },
{ 10, "黑河市" },
{ 10, "齐齐哈尔市" },
{ 11, "南京市" },
{ 11, "南通市" },
{ 11, "宿迁市" },
{ 11, "常州市" },
{ 11, "徐州市" },
{ 11, "扬州市" },
{ 11, "无锡市" },
{ 11, "泰州市" },
{ 11, "淮安市" },
{ 11, "盐城市" },
{ 11, "苏州市" },
{ 11, "连云港市" },
{ 11, "镇江市" },
{ 12, "丽水市" },
{ 12, "台州市" },
{ 12, "嘉兴市" },
{ 12, "宁波市" },
{ 12, "杭州市" },
{ 12, "温州市" },
{ 12, "湖州市" },
{ 12, "绍兴市" },
{ 12, "舟山市" },
{ 12, "衢州市" },
{ 12, "金华市" },
{ 13, "亳州市" },
{ 13, "六安市" },
{ 13, "合肥市" },
{ 13, "安庆市" },
{ 13, "宣城市" },
{ 13, "宿州市" },
{ 13, "池州市" },
{ 13, "淮北市" },
{ 13, "淮南市" },
{ 13, "滁州市" },
{ 13, "芜湖市" },
{ 13, "蚌埠市" },
{ 13, "铜陵市" },
{ 13, "阜阳市" },
{ 13, "马鞍山市" },
{ 13, "黄山市" },
{ 14, "三明市" },
{ 14, "南平市" },
{ 14, "厦门市" },
{ 14, "宁德市" },
{ 14, "泉州市" },
{ 14, "漳州市" },
{ 14, "福州市" },
{ 14, "莆田市" },
{ 14, "龙岩市" },
{ 15, "上饶市" },
{ 15, "九江市" },
{ 15, "南昌市" },
{ 15, "吉安市" },
{ 15, "宜春市" },
{ 15, "抚州市" },
{ 15, "新余市" },
{ 15, "景德镇市" },
{ 15, "萍乡市" },
{ 15, "赣州市" },
{ 15, "鹰潭市" },
{ 16, "东营市" },
{ 16, "临沂市" },
{ 16, "威海市" },
{ 16, "德州市" },
{ 16, "日照市" },
{ 16, "枣庄市" },
{ 16, "泰安市" },
{ 16, "济南市" },
{ 16, "济宁市" },
{ 16, "淄博市" },
{ 16, "滨州市" },
{ 16, "潍坊市" },
{ 16, "烟台市" },
{ 16, "聊城市" },
{ 16, "莱芜市" },
{ 16, "菏泽市" },
{ 16, "青岛市" },
{ 17, "三门峡市" },
{ 17, "信阳市" },
{ 17, "南阳市" },
{ 17, "周口市" },
{ 17, "商丘市" },
{ 17, "安阳市" },
{ 17, "平顶山市" },
{ 17, "开封市" },
{ 17, "新乡市" },
{ 17, "洛阳市" },
{ 17, "济源市" },
{ 17, "漯河市" },
{ 17, "濮阳市" },
{ 17, "焦作市" },
{ 17, "许昌市" },
{ 17, "郑州市" },
{ 17, "驻马店市" },
{ 17, "鹤壁市" },
{ 18, "仙桃市" },
{ 18, "十堰市" },
{ 18, "咸宁市" },
{ 18, "天门市" },
{ 18, "孝感市" },
{ 18, "宜昌市" },
{ 18, "恩施土家族苗族自治州" },
{ 18, "武汉市" },
{ 18, "潜江市" },
{ 18, "神农架林区" },
{ 18, "荆州市" },
{ 18, "荆门市" },
{ 18, "襄阳市" },
{ 18, "鄂州市" },
{ 18, "随州市" },
{ 18, "黄冈市" },
{ 18, "黄石市" },
{ 19, "娄底市" },
{ 19, "岳阳市" },
{ 19, "常德市" },
{ 19, "张家界市" },
{ 19, "怀化市" },
{ 19, "株洲市" },
{ 19, "永州市" },
{ 19, "湘潭市" },
{ 19, "湘西土家族苗族自治州" },
{ 19, "益阳市" },
{ 19, "衡阳市" },
{ 19, "邵阳市" },
{ 19, "郴州市" },
{ 19, "长沙市" },
{ 20, "东莞市" },
{ 20, "中山市" },
{ 20, "云浮市" },
{ 20, "佛山市" },
{ 20, "广州市" },
{ 20, "惠州市" },
{ 20, "揭阳市" },
{ 20, "梅州市" },
{ 20, "汕头市" },
{ 20, "汕尾市" },
{ 20, "江门市" },
{ 20, "河源市" },
{ 20, "深圳市" },
{ 20, "清远市" },
{ 20, "湛江市" },
{ 20, "潮州市" },
{ 20, "珠海市" },
{ 20, "肇庆市" },
{ 20, "茂名市" },
{ 20, "阳江市" },
{ 20, "韶关市" },
{ 21, "北海市" },
{ 21, "南宁市" },
{ 21, "崇左市" },
{ 21, "来宾市" },
{ 21, "柳州市" },
{ 21, "桂林市" },
{ 21, "梧州市" },
{ 21, "河池市" },
{ 21, "玉林市" },
{ 21, "百色市" },
{ 21, "贵港市" },
{ 21, "贺州市" },
{ 21, "钦州市" },
{ 21, "防城港市" },
{ 22, "万宁市" },
{ 22, "三亚市" },
{ 22, "东方市" },
{ 22, "临高县" },
{ 22, "乐东黎族自治县" },
{ 22, "五指山市" },
{ 22, "保亭黎族苗族自治县" },
{ 22, "儋州市" },
{ 22, "定安县" },
{ 22, "屯昌县" },
{ 22, "文昌市" },
{ 22, "昌江黎族自治县" },
{ 22, "海口市" },
{ 22, "澄迈县" },
{ 22, "琼中黎族苗族自治县" },
{ 22, "琼海市" },
{ 22, "白沙黎族自治县" },
{ 22, "陵水黎族自治县" },
{ 23, "乐山市" },
{ 23, "内江市" },
{ 23, "凉山彝族自治州" },
{ 23, "南充市" },
{ 23, "宜宾市" },
{ 23, "巴中市" },
{ 23, "广元市" },
{ 23, "广安市" },
{ 23, "德阳市" },
{ 23, "成都市" },
{ 23, "攀枝花市" },
{ 23, "泸州市" },
{ 23, "甘孜藏族自治州" },
{ 23, "眉山市" },
{ 23, "绵阳市" },
{ 23, "自贡市" },
{ 23, "资阳市" },
{ 23, "达州市" },
{ 23, "遂宁市" },
{ 23, "阿坝藏族羌族自治州" },
{ 23, "雅安市" },
{ 24, "六盘水市" },
{ 24, "安顺市" },
{ 24, "毕节市" },
{ 24, "贵阳市" },
{ 24, "遵义市" },
{ 24, "铜仁市" },
{ 24, "黔东南苗族侗族自治州" },
{ 24, "黔南布依族苗族自治州" },
{ 24, "黔西南布依族苗族自治州" },
{ 25, "临沧市" },
{ 25, "丽江市" },
{ 25, "保山市" },
{ 25, "大理白族自治州" },
{ 25, "德宏傣族景颇族自治州" },
{ 25, "怒江傈僳族自治州" },
{ 25, "文山壮族苗族自治州" },
{ 25, "昆明市" },
{ 25, "昭通市" },
{ 25, "普洱市" },
{ 25, "曲靖市" },
{ 25, "楚雄彝族自治州" },
{ 25, "玉溪市" },
{ 25, "红河哈尼族彝族自治州" },
{ 25, "西双版纳傣族自治州" },
{ 25, "迪庆藏族自治州" },
{ 26, "山南地区" },
{ 26, "拉萨市" },
{ 26, "日喀则地区" },
{ 26, "昌都地区" },
{ 26, "林芝地区" },
{ 26, "那曲地区" },
{ 26, "阿里地区" },
{ 27, "咸阳市" },
{ 27, "商洛市" },
{ 27, "安康市" },
{ 27, "宝鸡市" },
{ 27, "延安市" },
{ 27, "榆林市" },
{ 27, "汉中市" },
{ 27, "渭南市" },
{ 27, "西安市" },
{ 27, "铜川市" },
{ 28, "临夏回族自治州" },
{ 28, "兰州市" },
{ 28, "嘉峪关市" },
{ 28, "天水市" },
{ 28, "定西市" },
{ 28, "平凉市" },
{ 28, "庆阳市" },
{ 28, "张掖市" },
{ 28, "武威市" },
{ 28, "甘南藏族自治州" },
{ 28, "白银市" },
{ 28, "酒泉市" },
{ 28, "金昌市" },
{ 28, "陇南市" },
{ 29, "果洛藏族自治州" },
{ 29, "海东地区" },
{ 29, "海北藏族自治州" },
{ 29, "海南藏族自治州" },
{ 29, "海西蒙古族藏族自治州" },
{ 29, "玉树藏族自治州" },
{ 29, "西宁市" },
{ 29, "黄南藏族自治州" },
{ 30, "中卫市" },
{ 30, "吴忠市" },
{ 30, "固原市" },
{ 30, "石嘴山市" },
{ 30, "银川市" },
{ 31, "乌鲁木齐市" },
{ 31, "五家渠市" },
{ 31, "伊犁哈萨克自治州" },
{ 31, "克孜勒苏柯尔克孜自治州" },
{ 31, "克拉玛依市" },
{ 31, "博尔塔拉蒙古自治州" },
{ 31, "吐鲁番地区" },
{ 31, "和田地区" },
{ 31, "哈密地区" },
{ 31, "喀什地区" },
{ 31, "图木舒克市" },
{ 31, "塔城地区" },
{ 31, "巴音郭楞蒙古自治州" },
{ 31, "昌吉回族自治州" },
{ 31, "石河子市" },
{ 31, "阿克苏地区" },
{ 31, "阿勒泰地区" },
{ 31, "阿拉尔市" },
{ 32, "九龙" },
{ 32, "新界" },
{ 32, "香港岛" },
{ 33, "氹仔岛" },
{ 33, "澳门半岛" },
{ 33, "路环岛" }
};

static const char* ProvinceList[] = { "北京市", "天津市", "上海市", "重庆市", "河北省", "山西省",
    "内蒙古自治区", "辽宁省", "吉林省", "黑龙江省", "江苏省", "浙江省", "安徽省", "福建省", "江西省", "山东省",
    "河南省", "湖北省", "湖南省", "广东省", "广西壮族自治区", "海南省", "四川省", "贵州省", "云南省", "西藏自治区",
    "陕西省", "甘肃省", "青海省", "宁夏回族自治区", "新疆维吾尔自治区", "香港", "澳门" };

#define ITEMSOF( array ) (sizeof(array)/sizeof(array[0]))

const char* CityToProvince(const char* szCityName) {
  if (NULL == szCityName || 0 == *szCityName)
    return NULL;
  size_t nLenIn;
  nLenIn = strlen(szCityName);
  //printf("%d", ITEMSOF(CityList));
  for (unsigned int i = 0; i < ITEMSOF(CityList); i++) {
    if (0 == strncmp(szCityName, CityList[i].szCityName, nLenIn))
      return ProvinceList[CityList[i].nProvince - 1];
  }
  return NULL;
}

} /* namespace VA */
