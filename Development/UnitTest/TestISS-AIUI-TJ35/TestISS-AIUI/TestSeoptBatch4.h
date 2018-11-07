#ifndef SEOPT_BATCH_4_H_
#define SEOPT_BATCH_4_H_

#include"DefSeopt.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

class TestSeoptBatch4 {
private:
    ISSErrID err;
    ISSSeoptHandle phISSSeopt;
    DefSeopt def;
    int SeoptMode_;

public:
    TestSeoptBatch4();
    void test(std::string audio_list_path, std::string audio_out_path, bool IfNeedSleep, bool bIsSaveAudioOut);
    std::string GetAudioOutName(std::string audio_in_path, std::string strLabel);
    void SetParam(int SeoptMode) { SeoptMode_ = SeoptMode; };
};


#endif // !SEOPT_BATCH_H_