//---------------------------------------------------------------------------
//
// ���ۉ��ؘa���C���^�[�t�F�[�X
//
//      Programed by NAKAUE.T (Meister)
//
//  2001.08.12  Phase 6.2.1   FirstVersion
//
//---------------------------------------------------------------------------
#ifndef KOSUI_BASE_H
#define KOSUI_BASE_H
//---------------------------------------------------------------------------
#include "config.h"
//---------------------------------------------------------------------------
#include <string>
using namespace std;
//---------------------------------------------------------------------------
class TKawariInterface_base {
public:

	// �o�[�W�����ԍ���Ԃ�
	virtual string GetModuleVersion(void)=0;

	// �^����ꂽ�X�N���v�g�����߁E���s����
	virtual string Parse(const string& script)=0;
};
//---------------------------------------------------------------------------
#endif
