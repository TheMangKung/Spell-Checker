-Smart Spell Checker (C++ Trie Project)

-Project Overview
Smart Spell Checker เป็นโปรแกรมตรวจสอบคำสะกดและระบบ Auto-Complete พัฒนาโดยใช้ภาษา C++ และโครงสร้างข้อมูลแบบ Trie (Prefix Tree)
วัตถุประสงค์ของโปรเจกต์นี้คือเพื่อฝึกการใช้งานโครงสร้างข้อมูล Trie และการจัดการข้อมูลด้วย STL เช่น vector และ map รวมถึงการออกแบบโปรแกรมแบบเมนูโต้ตอบ (Interactive Console Application)

- Features
Check Word
ตรวจสอบว่าคำที่ผู้ใช้ป้อนมีอยู่ใน Dictionary หรือไม่ และบันทึกจำนวนครั้งที่มีการค้นหา
Auto-complete
แสดงรายการคำที่ขึ้นต้นด้วย prefix ที่ผู้ใช้ป้อน
Add New Word
เพิ่มคำใหม่เข้าไปใน Dictionary
Show All Dictionary Words
แสดงคำทั้งหมดที่อยู่ใน Dictionary โดยเรียงตามลำดับตัวอักษร
Show Statistics
แสดงจำนวนครั้งที่ผู้ใช้ค้นหาแต่ละคำ โดยใช้โครงสร้างข้อมูล map<string, int>

-Data Structure
Trie (Prefix Tree)
Trie เป็นโครงสร้างข้อมูลที่ใช้เก็บคำโดยแยกตามตัวอักษรแต่ละตัว เหมาะสำหรับงานที่เกี่ยวข้องกับการค้นหาคำและ prefix
โครงสร้างของ TrieNode:
struct TrieNode {
    bool isEnd;
    TrieNode* child[26];
};

-isEnd ใช้ระบุว่าตำแหน่งนั้นเป็นจุดสิ้นสุดของคำ
-child[26] ใช้เก็บตัวชี้ไปยังโหนดของตัวอักษร a-z

-Core Functions
-Utility Function
    toLowerCase(string s)
    แปลงตัวอักษรทั้งหมดในคำให้เป็นตัวพิมพ์เล็ก เพื่อป้องกันปัญหาตัวพิมพ์เล็ก-ใหญ่

-Trie Class
    insertWord(string word)
    เพิ่มคำเข้าไปใน Trie

    searchWord(string word)
    ตรวจสอบว่าคำนั้นมีอยู่ใน Trie หรือไม่

    autoComplete(string prefix)
    คืนค่ารายการคำทั้งหมดที่ขึ้นต้นด้วย prefix

    getAllWords()
    ดึงคำทั้งหมดใน Dictionary และเรียงลำดับก่อนส่งกลั

-Algorithm Complexity
ให้ L คือความยาวของคำ
Insert: O(L)
Search: O(L)
Auto-complete: O(L + k)
โดย k คือจำนวนคำที่ตรงกับ prefix
Trie มีประสิทธิภาพสูงสำหรับงานที่ต้องค้นหาคำจำนวนมากและทำงานกับ prefix บ่อยครั้ง

-Preloaded Dictionary
โปรแกรมมีคำศัพท์พื้นฐานเกี่ยวกับ Computer Science เช่น
algorithm, programming, structure, graph, pointer, class, template, debug, exception, memory