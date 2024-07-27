# rapidjson workload ����

### workload ����

rapidjson

### Ӧ�÷���

�������/json������

### rapidjson ����

**rapidjson** ��һ����C++��д��JSON������/�����������ܹ�����JSON��ʽ���ַ�����rapidjson����ϸ�ĵ���https://rapidjson.org/���Լ���GitHub�ϵ���Ŀ��ҳhttps://github.com/Tencent/rapidjson��rapidjson workload�ǻ���rapidjson v1.1.0������, ��ԭʼ�汾�Ĳ������£�

- ɾ��rapidjson��ʹ��rapidjson���ӣ��̳̣���Ԫ���ԣ��������⡣ֻ��������ҵ�����̣�����rapidjsonʹ����չָ����ԡ�
- �ü�ʹ�ñ�����MSVC���롣
- ɾ��û��ʹ�õ�ͷ�ļ���

### ����

��������ݼ���17����������Ŀsimdjson�У����ص�ַΪ��https://github.com/simdjson/simdjson-data�����ݼ�����Ϊ��
1. apache_builds.json
2. github_events.json
3. random.json
4. tree-pretty.json
5. twitterescaped.json
6. update-center.json
7. citm_catalog.json
8. google_maps_api_compact_response.json
9. instruments.json
10. repeat.json
11. twitter_api_compact_response.json
12. twitter.json
13. google_maps_api_response.json
14. mesh.pretty.json
15. semanticscholar-corpus.json
16. twitter_api_response.json
17. twitter_timeline.json

ʹ��g++��Ϊ�����������в���Ϊ��

```shell
-O3 -DNDEBUG -std=c++11
```

- -O3: ��ʾ����O3�Ż����Լ�
- -DNDEBUG:rapidjson�ڲ��ĺ꣬��ʾ����ǿ������
- -std=c++11:����C++11��׼���б���

### ��Ҫҵ������

1. **Parse**�����ڴ��е�JSON����ΪDOM�����ṹ��������RapidJSON�е�Parse������
2. **Stringify**����DOM���л�Ϊ�ڴ���ѹ����JSON���ַ������ͣ����յ�JSON���ʺ����紫���洢�����ʺ������Ķ�����
3. **Prettify**����DOM���л�Ϊ�ڴ��д�����JSON���������м��������������JSON��
4. **Statistics**������DOM������DOM�и����������͵������������ַ����������������������ȣ��Լ�������Ԫ�صĸ�����Object�ڳ�Ա�����ȡ�
5. **Sax Roundtrip**�����ڴ��е�JSON����Ϊ�¼�����ʹ���¼������ڴ��е�JSON��
6. **Sax Statistics**�����ڴ��е�JSON����Ϊ�¼�����ʹ���¼�����ͳ�ơ�

��ÿ�����ݼ�����ִ��1300�������6�����̡�

������ִ��һ��Parse��Stringify��Prettify���̣�����Stringify��Prettify������ڴ��е�JSON���ļ��У����׼�����������бȽϡ�

### ���

��������У�

* ���ÿ�����ݼ�����ϸ���ݣ��������ơ���С��object������array������number������string�����ȡ�
* ÿ�����ݼ�ִ��6����������ʱ�䡣
* �����ʱ�䣬��λΪs��
* ��֤���json���׼���������бȽϽ����

### �������

ISO C++11

### Դ�����license

rapidjson workload ����rapidjson v1.1.0�޸ģ���ʹ��MIT License����Լ�������ص�ַ��https://codeload.github.com/Tencent/rapidjson/tar.gz/refs/tags/v1.1.0

rapidjson workload ���ݼ�����Դsimd��Ŀ�Ĳ������ݣ���ѭApache-2.0 License����Լ����

### �ο���

[1]: https://github.com/Tencent/rapidjson
[2]: http://rapidjson.org/zh-cn/
