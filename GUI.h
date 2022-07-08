#include "service.h"
#include <qwidget.h>
#include <QtWidgets/QWidget>
#include <QtWidgets/qtableview.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qslider.h>
#include "Service.h"
#include <QtWidgets/QFormLayout.h>
#include <QtWidgets/QMessageBox.h>
#include <QPainter.h>

class MyView :public QAbstractTableModel {
	vector<Melodie> v;
	Service& s;
public:

	MyView(QObject* parent, Service& s) :s{ s }, QAbstractTableModel(parent){}

	//returneaza numarul de linii din tabel
	int rowCount(const QModelIndex& parent = QModelIndex()) const override {
		return v.size();
	}

	//returneaza numarul de coloane din tabel
	int columnCount(const QModelIndex& parent = QModelIndex()) const override {
		return 5;
	}

	//seteaza unde se vor stoca datele in tabel
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole)const override {
		if (role == Qt::DisplayRole)
		{
			Melodie a = v.at(index.row());
			if (index.column() == 0)
			{
				return QString::number(a.getId());
			}
			if (index.column() == 1)
			{
				return QString::fromStdString(a.getTitlu());
			}
			if (index.column() == 2)
			{
				return QString::fromStdString(a.getArtist());
			}
			if (index.column() == 3)
			{
				return QString::number(a.getRank());
			}
			if (index.column() == 4)
			{
				int nr = s.filtrareRank(a.getRank());
				return QString::number(nr);
			}
		}
		return QVariant();
	}

	//seteaza numele coloanelor din tabel
	QVariant headerData(int section, Qt::Orientation orientation, int role) const
	{
		if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
		{
			if (section == 0)
				return "ID";
			if (section == 1)
				return "TITLU";
			if (section == 2)
				return "ARTIST";
			if (section == 3)
				return "RANK";
			if (section == 4)
				return "ACELASI RANK";
		}

		return QVariant();
	}

	MyView() = default;

	//actualizeaza datele
	void setElems(vector<Melodie> ve)
	{
		v = ve;
		auto top = createIndex(0, 0);
		auto bottom = createIndex(ve.size(), 5);
		emit dataChanged(top, bottom);
		emit layoutChanged();
	}
};

class GUI : public QWidget {

	Service& s;

	MyView* model = new MyView(0, s);
	QTableView* tabel = new QTableView;

	QPushButton* btn_update = new QPushButton{ "Update" };
	QPushButton* btn_del = new QPushButton{ "Delete" };

	QLineEdit* titlu = new QLineEdit;
	QSlider* slider = new QSlider{ Qt::Horizontal };
	void initGUI();
	void connectSignals();

public:
	GUI(Service& service) : s{ service } {
		initGUI();
		connectSignals();
	}

};