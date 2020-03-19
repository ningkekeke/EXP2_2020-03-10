
// exp2.3View.cpp : Cexp23View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp23View 构造/析构

Cexp23View::Cexp23View()
{
	// TODO: 在此处添加构造代码

}

Cexp23View::~Cexp23View()
{
}

BOOL Cexp23View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp23View 绘制

void Cexp23View::OnDraw(CDC* pDC)
{
	Cexp23Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->A);
	pDC->Rectangle(pDoc->B);
	pDC->Rectangle(pDoc->C);
	// TODO: 在此处为本机数据添加绘制代码
}


// Cexp23View 打印

BOOL Cexp23View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cexp23View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cexp23View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Cexp23View 诊断

#ifdef _DEBUG
void Cexp23View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp23View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp23Doc* Cexp23View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp23Doc)));
	return (Cexp23Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp23View 消息处理程序


void Cexp23View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Cexp23Doc* pDoc = GetDocument();
	CString s1, s2, S;
	CClientDC dc(this);
	S.Format(_T("点击无效"));
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Cexp23Doc* pDoc = GetDocument();
	CString s;
	s.Format(_T("%d"), pDoc->a + pDoc->b);
	CClientDC dc(this);
	if (point.x >= 700 && point.x <= 900 && point.y >= 200 && point.y <= 300)
		dc.TextOutW(800, 250, s);
	CView::OnRButtonDown(nFlags, point);
}
