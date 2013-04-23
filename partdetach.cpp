#include "znc/IRCNetwork.h"
#include "znc/Modules.h"
#include "znc/Chan.h"

class CDetachPart : public CModule {
public:
        MODCONSTRUCTOR(CDetachPart) {}

        virtual EModRet OnUserPart(CString& sChannel, CString& sMessage) {
                CChan* pChan = m_pNetwork->FindChan(sChannel);

                if (pChan && !pChan->IsDetached() && sMessage != "..") {
                        pChan->DetachUser();
                        return HALTCORE;
                }

                return CONTINUE;
        }
};

NETWORKMODULEDEFS(CDetachPart, "Detach on part")