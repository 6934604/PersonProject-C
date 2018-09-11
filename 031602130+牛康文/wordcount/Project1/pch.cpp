
// pch.cpp: ��Ԥ�����ͷ��Ӧ��Դ�ļ�������ɹ��������

#include "pch.h"

	// һ������£����Դ��ļ����������ʹ�õ���Ԥ�����ͷ���뱣������
int QWE_wordCount::Atoatoint(char c) { //����д�ַ�ת��ΪСд��ĸ����hash��0~25���Լ���0~9hash��26~35.
	if (c >= 'A'&&c <= 'Z')c += 'A' - 'a';
	if (c >= 'a'&&c <= 'z') return c - 'a';
	else return c - '0' + 26;
}
char QWE_wordCount::FAtoatoint(int c) { //���ϸ������ķ�����
	if (c >= 0 && c <= 25)return 'a' + c;
	else return c - 26 + '0';
}
void QWE_wordCount::qinsert(string s) {  //�ֵ������뵥��
	int len = s.size(), tmp;
	node *p;
	p = &root;
	rep(i, 0, len) {
		tmp = Atoatoint(s[i]);
		if (p->next[tmp] == NULL) {
			p->next[tmp] = new node(); p->next[tmp]->gs = 0;
		}
		p = p->next[tmp];
		if (i == len - 1) { p->gs++; }
	}
}
void QWE_wordCount::MYscanf(char s[]) {  // �����ܿ���̨
	freopen(s, "r", stdin);
	//freopen("0.in", "r", stdin);
	string str;
	while (getline(cin, str)) {
		int len = str.size();
		line[num_line++] = str;
		if (len == 0)continue;
		bool f = 0;
		rep(i, 0, len) {
			if (str[i] != ' ')f = 1;
		}
		if (f) { eft_num++; }
	}
}
int QWE_wordCount::CountChar() {
	if (num_line == 0)return 0;
	int ret = 0;
	rep(i, 0, num_line) {
		int lim = line[i].size();
		rep(j, 0, lim) {
			if (line[i][j] >= 0 && line[i][j] <= 255)ret++;//ͳ����Ч�ַ�
		}
		ret++;//���ӻ��з�,ÿ�ж��У��������
	}
	return ret - 1;//���һ��û�л��з�����ȥ֮��
}
bool QWE_wordCount::is_efct_char(char c) { //�ж��Ƿ������ڵ��ʵ��ַ�
	if ((c >= '0'&&c <= '9') || (c >= 'A'&&c <= 'Z') || (c >= 'a'&&c <= 'z'))return true;
	return false;
}
int QWE_wordCount::CountWord() {
	int ret = 0;
	rep(i, 0, num_line) {
		bool f = 1; int lim = line[i].size();
		rep(j, 0, lim) {
			if (is_efct_char(line[i][j])) {
				string str = ""; str += line[i][j];
				rep(k, j + 1, lim) {
					if (is_efct_char(line[i][k]))str += line[i][k], j = k;
					else { j = k;  break; }
				}
				bool f = 0;; int siz = str.size();
				if (siz < 4)f = 1;
				else {
					rep(k, 0, 4) {
						if (str[k] >= '0'&&str[k] <= '9')f = 1;
					}
				}

				if (!f&&str.size() >= 4) {//�ж��Ƿ�����Ч����
					ret++;
					qinsert(str);//���ֵ����в����������,Ϊ���㵥�ʳ��ִ�����׼�����ֵ�����Լ�ռ��Լ�Ϊ����ͳ�ƴ��������ʱ�临�Ӷ�
				}
			}
		}
	}
	return ret;
}
void QWE_wordCount::dfs_getword(node u) {
	if (u.gs != 0) {
		qur.insert(make_pair(-u.gs, tmp));
		if (qur.size() > 10) {
			it = qur.end();
			it--;
			qur.erase(it);
		}
	}
	rep(i, 0, 36) {
		if (u.next[i] != NULL) {
			tmp += FAtoatoint(i);
			dfs_getword(*u.next[i]);
			tmp.erase(tmp.size() - 1);
		}
	}
}
void QWE_wordCount::CountMxWord() {
	qur.clear(); tmp = "";
	dfs_getword(root);
}
void QWE_wordCount::MYprint() {
	freopen("result.txt", "w", stdout);
	cout << "character: " << eft_char << endl;
	cout << "words: " << eft_word << endl;
	cout << "lines: " << eft_num << endl;
	for (it = qur.begin(); it != qur.end(); it++) {
		cout << "<" << it->second << ">: " << -it->first << endl;
	}
}
void QWE_wordCount::init() {
	root.gs = 0;
	num_line = 0, eft_num = 0, eft_char = 0, eft_word = 0;
}