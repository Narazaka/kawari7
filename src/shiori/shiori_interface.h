//---------------------------------------------------------------------------
//
// あれ以外の何か以外の何か
// SHIORI/2.3インターフェース
//
//      Programed by NAKAUE.T (Meister)
//
//  2001.05.22  Phase 5.1     SHIORI/2.3対応
//  2001.06.10  Phase 5.3.1   NAYUKIは廃止された
//  2001.07.10  Phase 6.0     getmoduleversion追加
//
//---------------------------------------------------------------------------
#ifndef SHIORI_INTERFACE_H
#define SHIORI_INTERFACE_H
//---------------------------------------------------------------------------
#include "config.h"
//---------------------------------------------------------------------------
#include <string>
using namespace std;
//---------------------------------------------------------------------------
// インターフェース規格のバージョン番号を返す
string Shiori_GetVersion(void);
//---------------------------------------------------------------------------
// 偽AIモジュールのバージョン番号を返す
string Shiori_GetModuleVersion(void);
//---------------------------------------------------------------------------
// モジュール読み込み時に呼ばれる
bool Shiori_Load(const string& dllpath);
//---------------------------------------------------------------------------
// モジュール切り離し時に呼ばれる
bool Shiori_Unload(void);
//---------------------------------------------------------------------------
// 偽AIリクエスト
string Shiori_Request(const string& requeststr);
//---------------------------------------------------------------------------
#endif
