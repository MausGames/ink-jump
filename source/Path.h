////////////////////////////////////////////////////
//*----------------------------------------------*//
//| Part of Ink Jump (https://www.maus-games.at) |//
//*----------------------------------------------*//
//| Copyright (c) 2024 Martin Mauersics          |//
//| Released under the zlib License              |//
//*----------------------------------------------*//
////////////////////////////////////////////////////
#pragma once
#ifndef _INJ_GUARD_PATH_H_
#define _INJ_GUARD_PATH_H_


// ****************************************************************
#define PATH_RESERVE_TRAILS (512u)
#define PATH_RESERVE_SPLATS (64u)
#define PATH_RESERVE_DROPS  (256u)


// ****************************************************************
class CPath final
{
private:
    coreList<coreObject3D*> m_apTrail;
    coreList<coreObject3D*> m_apSplat;
    coreList<coreObject3D*> m_apDrop;

    coreBatchList m_TrailList;
    coreBatchList m_SplatList;
    coreBatchList m_DropList;

    coreMemoryPool m_TrailMemory;
    coreMemoryPool m_SplatMemory;
    coreMemoryPool m_DropMemory;

    coreVector2 m_vLastPos;
    coreVector2 m_vLastDir;
    coreBool    m_bTrack;

    coreUint8 m_iCurTrail;
    coreUint8 m_iCurSplat;
    coreUint8 m_iCurDrop;


public:
    CPath()noexcept;
    ~CPath();

    DISABLE_COPY(CPath)

    void Render();
    void Move();

    void UpdateTrack(const coreVector2 vPosition);
    void StartTrack (const coreVector2 vPosition);
    void StopTrack  ();

    void AddSplat(const coreVector2 vPosition, const coreVector2 vVelocity);

    inline const coreBool& IsTracking()const {return m_bTrack;}


private:
    RETURN_RESTRICT coreObject3D* __CreateTrail();
    RETURN_RESTRICT coreObject3D* __CreateSplat();
    RETURN_RESTRICT coreObject3D* __CreateDrop ();
};


#endif // _INJ_GUARD_PATH_H_