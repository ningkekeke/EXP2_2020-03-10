
// exp2.3View.cpp : Cexp23View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp2.3.h"
#endif

#include "exp2.3Doc.h"
#include "exp2.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp23View

IMPLEMENT_DYNCREATE(Cexp23View, CView)

BEGIN_MESSAGE_MAP(Cexp23View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp23View ����/����

Cexp23View::Cexp23View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp23View::~Cexp23View()
{
}

BOOL Cexp23View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp23View ����

void Cexp23View::OnDraw(CDC* pDC)
{
	Cexp23Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->A);
	pDC->Rectangle(pDoc->B);
	pDC->Rectangle(pDoc->C);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp23View ��ӡ

BOOL Cexp23View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cexp23View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cexp23View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cexp23View ���

#ifdef _DEBUG
void Cexp23View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp23View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp23Doc* Cexp23View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp23Doc)));
	return (Cexp23Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp23View ��Ϣ�������


void Cexp23View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Cexp23Doc* pDoc = GetDocument();
	CString s1, s2, S;
	CClientDC dc(this);
	S.Format(_T("�����Ч"));
	if (point.x >= 100 && point.x <= 300 && point.y >= 200 && point.y <= 300)
	{
		pDoc->a = rand();
		s1.Format(_T("%d"), pDoc->a);
		dc.TextOutW(200, 250, s1);
	}
	else if (point.x >= 400 && point.x <= 600 && point.y >= 200 && point.y <= 300)
	{
		pDoc->b = rand();
		s2.Format(_T("%d"), pDoc->b);
		dc.TextOutW(500, 250, s2);
	}
	else
		dc.TextOutW(450, 400, S);
	CView::OnLButtonDown(nFlags, point);
}


void Cexp23View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Cexp23Doc* pDoc = GetDocument();
	CString s;
	s.Format(_T("%d"), pDoc->a + pDoc->b);
	CClientDC dc(this);
	if (point.x >= 700 && point.x <= 900 && point.y >= 200 && point.y <= 300)
		dc.TextOutW(800, 250, s);
	CView::OnRButtonDown(nFlags, point);
}
