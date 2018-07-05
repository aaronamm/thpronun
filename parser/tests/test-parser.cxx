#include "parser/parser.h"
#include "output/sylout-thai.h"
#include "output/sylout-roman.h"
#include "output/output-delim.h"
#include "output/output-roman.h"
#include "output/output-gjson.h"

#include <iostream>
#include <memory>

using namespace std;

bool ParseAll (const Parser& parser, list<string> words)
{
    DelimOutput thaiOutput (make_unique<ThaiSylOutput>(), '-');
    RomanOutput romanOutput;

    for (auto w : words) {
        cout << w << ':' << endl;
        auto pronDAG = parser.parseWord (w);
        cout << thaiOutput.output (pronDAG) << endl;
        cout << romanOutput.output (pronDAG) << endl;
    }

    GroupedJsonOutput gJsonOutput (make_unique<ThaiSylOutput>());

    for (auto w : words) {
        cout << w << ':' << endl;
        auto pronDAG = parser.parseWord (w);
        cout << gJsonOutput.output (pronDAG) << endl;
    }

    return true;
}

bool
TestThCons()
{
    list<string> thConsSimple = {
        u8"กง",
        u8"กัง",
        u8"หงส์",
        u8"ข้น",
        u8"กวง",
        u8"ก่อ",
        u8"ก้อน",
        u8"ช็อป",
        u8"ฟอร์ม",
        u8"พร",
        u8"ภรณ์",
        u8"สรร",
        u8"ธรรม",
        u8"สวรรค์",
        u8"ค่ะ",
        u8"ค่ะส์",
        u8"วัน",
        u8"จันทร์",
        u8"ทันต์",
        u8"มั่ว",
        u8"ชัวร์",
        u8"ผัวะ",
        u8"จั๊วะ",
        u8"ข้า",
        u8"พาร์",
        u8"ข้าง",
        u8"ฟาร์ม",
        u8"ศาสตร์",
        u8"ขำ",
        u8"ค่ำ",
        u8"ขำส์",
        u8"สิ",
        u8"ซิ่น",
        u8"ฟิล์ม",
        u8"ที่",
        u8"พีร์",
        u8"อึ",
        u8"ขึ้น",
        u8"ซื่อ",
        u8"ขืน",
        u8"ผื่น",
        u8"ดุ",
        u8"คุก",
        u8"ดู",
        u8"ปู้ด",
    };

    list<string> thConsCluster = {
        u8"กรง",
        u8"กรงส์",
        u8"คลาด",
        u8"ตราด",
        u8"ปลอบ",
        u8"ขวาน",
        u8"ควาย",
        u8"ขวิด",
        u8"สราญ",
        u8"สรวง",
        u8"จริง",
        u8"สมัน",
        u8"สมร",
    };

    list<string> thConsLinked = {
        u8"อัตรา",
        u8"มาตรา",
        u8"จักรี",
        u8"จัตุรัส",
    };

    list<string> thConsComplicated = {
        u8"อุปสรรค",
        u8"อัปสร",
        u8"วิศวกร",
    };

    list<string> thConsAu = {
        u8"กรกฎ",
        u8"ครหา",
        u8"จระเข้",
        u8"จรลี",
        u8"ทรชน",
        u8"ทรมาน",
        u8"ธรณี",
        u8"นรชาติ",
        u8"นรสีห์",
        u8"บดี",
        u8"บดินทร์",
        u8"อธิบดี",
        u8"นฤบดินทร์",
        u8"บรบือ",
        u8"บริบูรณ์",
        u8"บริเวณ",
        u8"บริษัท",
        u8"ปรโลก",
        u8"ภรณี",
        u8"มรณะ",
        u8"มรดก",
        u8"สรพงษ์",
        u8"สรยุทธ์",
        u8"สรศักดิ์",
        u8"หรคุณ",
        u8"หรดี",
        u8"อรสา",
        u8"อรดี",
    };

    bool isSuccess = true;

    Parser parser;

    cout << "TestThCons: Simple forms..." << endl;
    if (!ParseAll (parser, thConsSimple)) {
        isSuccess = false;
    }
    cout << endl;

    cout << "TestThCons: With cluster as initial consonants..." << endl;
    if (!ParseAll (parser, thConsCluster)) {
        isSuccess = false;
    }
    cout << endl;

    cout << "TestThCons: With linked syllables..." << endl;
    if (!ParseAll (parser, thConsLinked)) {
        isSuccess = false;
    }
    cout << endl;

    cout << "TestThCons: Complicated forms..." << endl;
    if (!ParseAll (parser, thConsComplicated)) {
        isSuccess = false;
    }
    cout << endl;

    cout << "TestThCons: AU consonant sound..." << endl;
    if (!ParseAll (parser, thConsAu)) {
        isSuccess = false;
    }
    cout << endl;

    list<string> nbTests = {
        u8"อุดรรัถยา",
        u8"อุดรรโหฐาน",
    };

    cout << "TestThCons: no word break..." << endl;
    Parser nbParser (false);
    if (!ParseAll (nbParser, nbTests)) {
        isSuccess = false;
    }
    cout << endl;

    return isSuccess;
}

bool
TestSaraE()
{
    list<string> saraE = {
        u8"เก",
        u8"เท่",
        u8"เพล",
        u8"เก่ง",
        u8"เล่ห์",
        u8"เสน่ห์",
        u8"เถลไถล",
        u8"เตะ",
        u8"เป๊ะ",
        u8"เละส์",
        u8"เผละ",
        u8"เสเพล",
        u8"เหล่",
        u8"เกว๋",
        u8"เชวง",
        u8"เป็น",
    };

    list<string> saraOE = {
        u8"เธอ",
        u8"เสนอ",
        u8"เปอร์เซ็นต์",
        u8"เลอะ",
        u8"เปรอะ",
        u8"เกิด",
        u8"เกิร์ต",
        u8"เปิ่น",
        u8"เพลิน",
        u8"เคลิ้ม",
        u8"เสริม",
        u8"เลย",
        u8"เม้ย",
        u8"เมย์",
        u8"เหมย",
        u8"เชลย",
        u8"เบรยล์",
    };

    list<string> saraIA = {
        u8"เซียะ",
        u8"เปี๊ยะ",
        u8"เปรี๊ยะ",
        u8"เกี๊ยะส์",
        u8"เสีย",
        u8"เชียร์",
        u8"เพลีย",
        u8"เสียด",
        u8"เพี้ยน",
        u8"เสนียด",
        u8"เฟียร์ตส์",
    };

    list<string> saraUEA = {
        u8"ละเวือะ",
        u8"เกื๊อะ",
        u8"เคือะส์",
        u8"เกือบ",
        u8"เลื่อน",
        u8"เกลือ",
        u8"เกลือก",
        u8"เสมือน",
        u8"เถลือกถลน",
        u8"เหมือน",
        u8"เวือร์ต",
    };

    list<string> saraAW = {
        u8"เกา",
        u8"เกลา",
        u8"เสลา",
        u8"เหมา",
        u8"เสาร์",
    };

    list<string> saraAU = {
        u8"เกาะ",
        u8"เพลาะ",
        u8"เสนาะ",
        u8"เหมาะ",
        u8"เคราะห์",
    };

    bool isSuccess = true;

    Parser parser;

    cout << "TestSareE: Sara E..." << endl;
    if (!ParseAll (parser, saraE)) {
        isSuccess = false;
    }
    cout << endl;

    cout << "TestThCons: Sara OE..." << endl;
    if (!ParseAll (parser, saraOE)) {
        isSuccess = false;
    }
    cout << endl;

    cout << "TestThCons: Sara IA..." << endl;
    if (!ParseAll (parser, saraIA)) {
        isSuccess = false;
    }
    cout << endl;

    cout << "TestThCons: Sara UEA..." << endl;
    if (!ParseAll (parser, saraUEA)) {
        isSuccess = false;
    }
    cout << endl;

    cout << "TestThCons: Sara AW..." << endl;
    if (!ParseAll (parser, saraAW)) {
        isSuccess = false;
    }
    cout << endl;

    cout << "TestThCons: Sara AU..." << endl;
    if (!ParseAll (parser, saraAU)) {
        isSuccess = false;
    }
    cout << endl;

    return isSuccess;
}

bool
TestOtherLV()
{
    list<string> saraAE = {
        u8"แก",
        u8"แก่",
        u8"แชร์",
        u8"แฟร์มาต์",
        u8"แกล",
        u8"แก้ม",
        u8"แพทย์",
        u8"แสม",
        u8"แตะ",
        u8"แป๊ะ",
        u8"แกละ",
        u8"แสยะ",
        u8"แหล่",
        u8"แกว่ง",
        u8"แพลง",
        u8"แสลง",
        u8"แข็ง",
    };

    list<string> saraO = {
        u8"โต",
        u8"โอ่",
        u8"โฟร์",
        u8"โละ",
        u8"โป๊ะ",
        u8"โพละ",
        u8"โกน",
        u8"โล้น",
        u8"โสน",
        u8"โกลน",
        u8"โขดง",
    };

    list<string> saraAI = {
        u8"ใจ",
        u8"ใช้",
        u8"ใคร",
        u8"ใคร่",
        u8"ไก",
        u8"ไล่",
        u8"ไพล่",
        u8"ไฉน",
        u8"ไดร์",
    };

    bool isSuccess = true;

    Parser parser;

    cout << "TestSareE: Sara AE..." << endl;
    if (!ParseAll (parser, saraAE)) {
        isSuccess = false;
    }
    cout << endl;

    cout << "TestThCons: Sara O..." << endl;
    if (!ParseAll (parser, saraO)) {
        isSuccess = false;
    }
    cout << endl;

    cout << "TestThCons: Sara AI..." << endl;
    if (!ParseAll (parser, saraAI)) {
        isSuccess = false;
    }
    cout << endl;

    return isSuccess;
}

bool
TestRu()
{
    list<string> ru = {
        u8"อังกฤษ",
        u8"ตฤณ",
        u8"ทฤษฎี",
        u8"ปฤจฉา",
        u8"สฤษดิ์",
        u8"ศฤงคาร",
        u8"คฤนถ์",
        u8"คฤหัสถ์",
        u8"คฤโฆษ",
        u8"นฤพาน",
        u8"นฤมิต",
        u8"พฤกษ์",
        u8"พฤฒาจารย์",
        u8"พฤหัส",
        u8"มฤค",
        u8"หฤทัย",
        u8"หฤหรรษ์",
        u8"หฤโหด",
        u8"ฤดี",
        u8"ฤดู",
        u8"ฤทัย",
        u8"ฤชา",
        u8"ฤคเวท",
        u8"ฤกษณะ",
        u8"ฤต",
        u8"ฤทธิ์",
        u8"ฤณ",
        u8"ฤษยา",
        u8"ฤๅษี",
        u8"ฦๅสาย",
    };

    bool isSuccess = true;

    Parser parser;

    cout << "TestRu: Words containg RU..." << endl;
    if (!ParseAll (parser, ru)) {
        isSuccess = false;
    }
    cout << endl;

    return isSuccess;
}

bool
TestMuteECons()
{
    list<string> muteECons = {
        u8"จักร",
        u8"สมัคร",
        u8"เพชร",
        u8"วัตร",
        u8"เมตร",
        u8"มาตร",
        u8"บพิตร",
        u8"มิตร",
        u8"จิตร",
        u8"ปริตร",
        u8"มูตร",
        u8"โคตร",
        u8"โพธิ",
        u8"โพธิ์",
        u8"โพธิสาร",
        u8"สมุทร",
        u8"กอปร",
        u8"สมบัติ",
        u8"ชาติ",
        u8"ชาติพันธุ์",
        u8"ประวัติ",
        u8"ประวัติศาสตร์",
        u8"ธาตุ",
        u8"เกตุ",
        u8"เหตุ",
        u8"เมรุ",
        u8"พยาธิ",
        u8"ขัดสมาธิ",
    };

    bool isSuccess = true;

    Parser parser;

    cout << "TestRu: Words containg muted end cons..." << endl;
    if (!ParseAll (parser, muteECons)) {
        isSuccess = false;
    }
    cout << endl;

    return isSuccess;
}

bool
TestExceptDict()
{
    bool isSuccess = true;

    Parser parser;
    if (!parser.loadExceptDict ("except.dic")) {
        cerr << "Failed to load exception dict 'except.dic'" << endl;
        isSuccess = false;
    }

    list<string> exceptSamples = {
        u8"สามารถปรารถนาได้",
        u8"ได้ปรารถนาเป็นสามารถ",
        u8"สวัสดิการ",
        u8"สวัสดิ์",
    };

    cout << "Test parsing with exception dictionary..." << endl;
    if (!ParseAll (parser, exceptSamples)) {
        isSuccess = false;
    }
    cout << endl;

    return isSuccess;
}

bool
TestWordBreak()
{
    bool isSuccess = true;

    list<string> longSamples = {
        u8"กุมบังเหียนชีวิตประชาชน",
        u8"กองบัญชาการทหารสูงสุด",
    };

    cout << "Test parsing without word break..." << endl;
    Parser noBrkParser (false);
    if (!ParseAll (noBrkParser, longSamples)) {
        isSuccess = false;
    }
    cout << endl;

    cout << "Test parsing with word break..." << endl;
    Parser brkParser (true);
    if (!ParseAll (brkParser, longSamples)) {
        isSuccess = false;
    }
    cout << endl;

    return isSuccess;
}

bool
TestNonWordChar()
{
    bool isSuccess = true;

    list<string> nonWordSamples = {
        u8"กรุงเทพฯ",
        u8"กรุงเทพฯ 10800 ประเทศไทย",
        u8"งูๆ ปลาๆ",
        u8"@ปื๊ด",
        u8"a",
    };

    cout << "Test parsing non-word chars..." << endl;
    Parser parser;
    if (!ParseAll (parser, nonWordSamples)) {
        isSuccess = false;
    }
    cout << endl;

    return isSuccess;
}

int
main()
{
    bool isSuccess = true;

    if (!TestThCons()) {
        isSuccess = false;
    }

    if (!TestSaraE()) {
        isSuccess = false;
    }

    if (!TestOtherLV()) {
        isSuccess = false;
    }

    if (!TestRu()) {
        isSuccess = false;
    }

    if (!TestMuteECons()) {
        isSuccess = false;
    }

    if (!TestExceptDict()) {
        isSuccess = false;
    }

    if (!TestWordBreak()) {
        isSuccess = false;
    }

    if (!TestNonWordChar()) {
        isSuccess = false;
    }

    return isSuccess ? 0 : 1;
}

/*
vi:ts=4:ai:expandtab
*/
