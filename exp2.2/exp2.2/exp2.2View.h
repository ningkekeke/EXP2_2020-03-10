
// exp2.2View.h : Cexp22View ��Ľӿ�
//

#pragma once


class Cexp22View : public CView
{
protected: // �������л�����
	Cexp22View();
	DECLARE_DYNCREATE(Cexp22View)

// ����
public:
	Cexp22Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~Cexp22View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // exp2.2View.cpp �еĵ��԰汾
inline Cexp22Doc* Cexp22View::GetDocument() const
   { return reinterpret_cast<Cexp22Doc*>(m_pDocument); }
#endif

