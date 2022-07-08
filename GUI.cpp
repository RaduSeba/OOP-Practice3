#include "GUI.h"
#include <string>

//initializare GUI
void GUI::initGUI()
{
    auto layout_mare = new QVBoxLayout;
    auto layout_st = new QVBoxLayout;
    auto layout_dr = new QVBoxLayout;

    auto layout_main = new QHBoxLayout;

    this->setLayout(layout_mare);
    layout_mare->addLayout(layout_main);
    layout_main->addLayout(layout_st);
    layout_main->addLayout(layout_dr);

    auto form = new QFormLayout;

    tabel->setModel(model);
    model->setElems(s.getAll());
    form->addRow("Titlu: ", titlu);
    form->addRow("Rank: ", slider);
    slider->setRange(0, 10);
    layout_st->addLayout(form);
    layout_dr->addWidget(tabel);
    layout_st->addWidget(btn_update);
    layout_st->addWidget(btn_del);


}

//preia datele de pe linia cu id-ul selectat si reflecta titlu si rankul in sectiunea de titlu, respectiv la pozitia sliderului
void GUI::connectSignals()
{
    QObject::connect(tabel->selectionModel(), &QItemSelectionModel::selectionChanged, [&]() {
        auto sModel = tabel->selectionModel();
        if (sModel->selectedIndexes().isEmpty())
            return;
        auto index = sModel->selectedIndexes().at(0);

        vector<Melodie> v = s.getAll();
        int id = index.data(Qt::DisplayRole).toInt();
        for (Melodie m : v)
        {
            if (m.getId() == id)
            {
                titlu->setText(QString::fromStdString(m.getTitlu()));
                slider->setValue(m.getRank());
            }
        }
        });

    //conectarea butonului de update care modifica titlul/rank-ul unei melodii
    QObject::connect(btn_update, &QPushButton::clicked, this, [&]() {
        auto sModel = tabel->selectionModel();
        if (sModel->selectedIndexes().isEmpty())
            return;
        auto index = sModel->selectedIndexes().at(0);
        int id = index.data(Qt::DisplayRole).toInt();
        s.modifica(id, titlu->text().toStdString(), slider->value());
        model->setElems(s.getAll());

        });

    //conectarea butonului de delete ce efectueaza stergerea unei melodii in cazul in care nu e ultima ramasa a artistului
    QObject::connect(btn_del, &QPushButton::clicked, this, [&]() {
        auto sModel = tabel->selectionModel();
        if (sModel->selectedIndexes().isEmpty())
            return;
        auto index = sModel->selectedIndexes().at(0);
        int id = index.data(Qt::DisplayRole).toInt();
        vector<Melodie> v = s.getAll();
        int nr = 0;
        string artist;
        for (Melodie m : v)
        {
            if (m.getId() == id)
            {
                artist = m.getArtist();
                break;
            }
        }
        for (Melodie m : v)
        {
            if (m.getArtist() == artist)
                nr++;
        }
        if (nr == 1)
        {
            QMessageBox::warning(nullptr, "Error", "Este ultima melodie a artistului deci nu se poate sterge!");
            return;
        }
        s.stergere(id);

        model->setElems(s.getAll());
        });
}

