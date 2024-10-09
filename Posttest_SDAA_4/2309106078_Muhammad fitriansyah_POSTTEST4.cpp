#include <iostream>
#include <string>

using namespace std;

struct Sparepart {
    string kodeSparepart;
    string namaSparepart;
    int stok;
    float harga;
    Sparepart* next;  // Pointer to the next node
};

Sparepart* head = nullptr; // Pointer to the head of the list

// Fungsi untuk menambah sparepart
void tambahSparepart() {
    Sparepart* sparepartBaru = new Sparepart;
    
    cout << "Masukkan Kode Sparepart: ";
    cin >> sparepartBaru->kodeSparepart;
    cout << "Masukkan Nama Sparepart: ";
    cin.ignore();
    getline(cin, sparepartBaru->namaSparepart);
    cout << "Masukkan Stok: ";
    cin >> sparepartBaru->stok;
    cout << "Masukkan Harga: ";
    cin >> sparepartBaru->harga;

    sparepartBaru->next = nullptr; // Set next to null, since it will be the last node for now

    if (head == nullptr) {
        head = sparepartBaru;
    } else {
        Sparepart* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = sparepartBaru;
    }

    cout << "Sparepart berhasil ditambahkan!" << endl;
}

// Fungsi untuk menampilkan semua sparepart
void tampilkanSpareparts() {
    if (head == nullptr) {
        cout << "Tidak ada sparepart dalam daftar." << endl;
        return;
    }

    Sparepart* temp = head;
    cout << "Daftar Sparepart Motor: " << endl;
    while (temp != nullptr) {
        cout << "Kode: " << temp->kodeSparepart << ", Nama: " << temp->namaSparepart
             << ", Stok: " << temp->stok << ", Harga: Rp" << temp->harga << endl;
        temp = temp->next;
    }
}

// Fungsi untuk update sparepart
void updateSparepart() {
    string kode;
    cout << "Masukkan kode sparepart yang ingin diupdate: ";
    cin >> kode;

    Sparepart* temp = head;
    while (temp != nullptr) {
        if (temp->kodeSparepart == kode) {
            cout << "Masukkan Nama Sparepart Baru: ";
            cin.ignore();
            getline(cin, temp->namaSparepart);
            cout << "Masukkan Stok Baru: ";
            cin >> temp->stok;
            cout << "Masukkan Harga Baru: ";
            cin >> temp->harga;
            cout << "Sparepart berhasil diupdate!" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Sparepart dengan kode tersebut tidak ditemukan." << endl;
}

// Fungsi untuk menghapus sparepart
void hapusSparepart() {
    string kode;
    cout << "Masukkan kode sparepart yang ingin dihapus: ";
    cin >> kode;

    if (head == nullptr) {
        cout << "Daftar kosong, tidak ada yang bisa dihapus." << endl;
        return;
    }

    if (head->kodeSparepart == kode) {
        Sparepart* temp = head;
        head = head->next;
        delete temp;
        cout << "Sparepart berhasil dihapus!" << endl;
        return;
    }

    Sparepart* current = head;
    Sparepart* previous = nullptr;

    while (current != nullptr && current->kodeSparepart != kode) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Sparepart dengan kode tersebut tidak ditemukan." << endl;
        return;
    }

    previous->next = current->next;
    delete current;
    cout << "Sparepart berhasil dihapus!" << endl;
}

// Implementasi STACK menggunakan Linked List
Sparepart* top = nullptr;  // Inisialisasi stack kosong

// Fungsi untuk menambah sparepart ke stack (push)
void pushSparepart() {
    Sparepart* sparepartBaru = new Sparepart;

    cout << "Masukkan Kode Sparepart: ";
    cin >> sparepartBaru->kodeSparepart;
    cout << "Masukkan Nama Sparepart: ";
    cin.ignore();
    getline(cin, sparepartBaru->namaSparepart);
    cout << "Masukkan Stok: ";
    cin >> sparepartBaru->stok;
    cout << "Masukkan Harga: ";
    cin >> sparepartBaru->harga;

    sparepartBaru->next = top;
    top = sparepartBaru;

    cout << "Sparepart berhasil ditambahkan ke Stack!" << endl;
}

// Fungsi untuk mengeluarkan sparepart dari stack (pop)
void popSparepart() {
    if (top == nullptr) {
        cout << "Stack kosong, tidak ada yang bisa di-pop." << endl;
        return;
    }

    Sparepart* temp = top;
    top = top->next;
    delete temp;

    cout << "Sparepart berhasil di-pop dari Stack!" << endl;
}

// Fungsi untuk menampilkan sparepart di Stack
void tampilkanStack() {
    if (top == nullptr) {
        cout << "Stack kosong." << endl;
        return;
    }

    Sparepart* temp = top;
    cout << "Spareparts di Stack: " << endl;
    while (temp != nullptr) {
        cout << "Kode: " << temp->kodeSparepart << ", Nama: " << temp->namaSparepart
             << ", Stok: " << temp->stok << ", Harga: Rp" << temp->harga << endl;
        temp = temp->next;
    }
}

// Implementasi QUEUE menggunakan Linked List
Sparepart* front = nullptr; // Inisialisasi queue kosong
Sparepart* rear = nullptr;

// Fungsi untuk menambah sparepart ke queue (enqueue)
void enqueueSparepart() {
    Sparepart* sparepartBaru = new Sparepart;

    cout << "Masukkan Kode Sparepart: ";
    cin >> sparepartBaru->kodeSparepart;
    cout << "Masukkan Nama Sparepart: ";
    cin.ignore();
    getline(cin, sparepartBaru->namaSparepart);
    cout << "Masukkan Stok: ";
    cin >> sparepartBaru->stok;
    cout << "Masukkan Harga: ";
    cin >> sparepartBaru->harga;

    sparepartBaru->next = nullptr;
    if (rear == nullptr) {
        front = rear = sparepartBaru;
    } else {
        rear->next = sparepartBaru;
        rear = sparepartBaru;
    }

    cout << "Sparepart berhasil ditambahkan ke Queue!" << endl;
}

// Fungsi untuk mengeluarkan sparepart dari queue (dequeue)
void dequeueSparepart() {
    if (front == nullptr) {
        cout << "Queue kosong, tidak ada yang bisa di-dequeue." << endl;
        return;
    }

    Sparepart* temp = front;
    front = front->next;

    if (front == nullptr) {
        rear = nullptr;
    }

    delete temp;
    cout << "Sparepart berhasil di-dequeue dari Queue!" << endl;
}

// Fungsi untuk menampilkan sparepart di Queue
void tampilkanQueue() {
    if (front == nullptr) {
        cout << "Queue kosong." << endl;
        return;
    }

    Sparepart* temp = front;
    cout << "Spareparts di Queue: " << endl;
    while (temp != nullptr) {
        cout << "Kode: " << temp->kodeSparepart << ", Nama: " << temp->namaSparepart
             << ", Stok: " << temp->stok << ", Harga: Rp" << temp->harga << endl;
        temp = temp->next;
    }
}

// Menu program
void menu() {
    int pilihan;
    do {
        cout << "\nMenu Manajemen Penjualan Sparepart Motor:" << endl;
        cout << "1. Tambah Sparepart (Linked List)" << endl;
        cout << "2. Tampilkan Sparepart (Linked List)" << endl;
        cout << "3. Update Sparepart (Linked List)" << endl;
        cout << "4. Hapus Sparepart (Linked List)" << endl;
        cout << "5. Tambah Sparepart ke Stack" << endl;
        cout << "6. Pop Sparepart dari Stack" << endl;
        cout << "7. Tampilkan Stack" << endl;
        cout << "8. Tambah Sparepart ke Queue" << endl;
        cout << "9. Dequeue Sparepart dari Queue" << endl;
        cout << "10. Tampilkan Queue" << endl;
        cout << "11. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahSparepart();
                break;
            case 2:
                tampilkanSpareparts();
                break;
            case 3:
                updateSparepart();
                break;
            case 4:
                hapusSparepart();
                break;
            case 5:
                pushSparepart();
                break;
            case 6:
                popSparepart();
                break;
            case 7:
                tampilkanStack();
                break;
            case 8:
                enqueueSparepart();
                break;
            case 9:
                dequeueSparepart();
                break;
            case 10:
                tampilkanQueue();
                break;
            case 11:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (pilihan != 11);
}

int main() {
    menu();
    return 0;
}
