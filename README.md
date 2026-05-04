Last login: Sun May  3 17:55:08 on ttys000
vipul.shukla@MAC-KGX5DFMHPX ~ % cd Documents/pg_avac 
vipul.shukla@MAC-KGX5DFMHPX pg_avac % # 1. Create a new repo on github.com (call it pg_avac, leave it empty)

# 2. Then from your local machine:
git clone <this project> pg_avac   # or copy the files
cd pg_avac
git remote add origin https://github.com/YOUR_USERNAME/pg_avac.git
git branch -M main
git push -u origin main
zsh: number expected
zsh: command not found: #
zsh: no such file or directory: this
cd: no such file or directory: pg_avac
fatal: not a git repository (or any of the parent directories): .git
fatal: not a git repository (or any of the parent directories): .git
fatal: not a git repository (or any of the parent directories): .git
vipul.shukla@MAC-KGX5DFMHPX pg_avac % git clone . pg_avac          
fatal: repository '.' does not exist
vipul.shukla@MAC-KGX5DFMHPX pg_avac % git clone pg_avac pg_avac
fatal: repository 'pg_avac' does not exist
vipul.shukla@MAC-KGX5DFMHPX pg_avac % git --help
usage: git [-v | --version] [-h | --help] [-C <path>] [-c <name>=<value>]
           [--exec-path[=<path>]] [--html-path] [--man-path] [--info-path]
           [-p | --paginate | -P | --no-pager] [--no-replace-objects] [--no-lazy-fetch]
           [--no-optional-locks] [--no-advice] [--bare] [--git-dir=<path>]
           [--work-tree=<path>] [--namespace=<name>] [--config-env=<name>=<envvar>]
           <command> [<args>]

These are common Git commands used in various situations:

start a working area (see also: git help tutorial)
   clone      Clone a repository into a new directory
   init       Create an empty Git repository or reinitialize an existing one

work on the current change (see also: git help everyday)
   add        Add file contents to the index
   mv         Move or rename a file, a directory, or a symlink
   restore    Restore working tree files
   rm         Remove files from the working tree and from the index

examine the history and state (see also: git help revisions)
   bisect     Use binary search to find the commit that introduced a bug
   diff       Show changes between commits, commit and working tree, etc
   grep       Print lines matching a pattern
   log        Show commit logs
   show       Show various types of objects
   status     Show the working tree status

grow, mark and tweak your common history
   backfill   Download missing objects in a partial clone
   branch     List, create, or delete branches
   commit     Record changes to the repository
   merge      Join two or more development histories together
   rebase     Reapply commits on top of another base tip
   reset      Reset current HEAD to the specified state
   switch     Switch branches
   tag        Create, list, delete or verify a tag object signed with GPG

collaborate (see also: git help workflows)
   fetch      Download objects and refs from another repository
   pull       Fetch from and integrate with another repository or a local branch
   push       Update remote refs along with associated objects

'git help -a' and 'git help -g' list available subcommands and some
concept guides. See 'git help <command>' or 'git help <concept>'
to read about a specific subcommand or concept.
See 'git help git' for an overview of the system.
vipul.shukla@MAC-KGX5DFMHPX pg_avac % git init pg_avac
Initialized empty Git repository in /Users/vipul.shukla/Documents/pg_avac/pg_avac/.git/
vipul.shukla@MAC-KGX5DFMHPX pg_avac % git clone pg_avac pg_avac
fatal: destination path 'pg_avac' already exists and is not an empty directory.
vipul.shukla@MAC-KGX5DFMHPX pg_avac % ls                       
LICENSE		Makefile	pg_avac		pg_avac.control	pg_avac.h	README.md
vipul.shukla@MAC-KGX5DFMHPX pg_avac % ls -l
total 56
-rw-------@ 1 vipul.shukla  staff   948 May  4  2026 LICENSE
-rw-------@ 1 vipul.shukla  staff   243 May  4  2026 Makefile
drwxr-xr-x  3 vipul.shukla  staff    96 May  4 16:46 pg_avac
-rw-------@ 1 vipul.shukla  staff   188 May  4  2026 pg_avac.control
-rw-------@ 1 vipul.shukla  staff  5707 May  4  2026 pg_avac.h
-rw-------@ 1 vipul.shukla  staff  7265 May  4  2026 README.md
vipul.shukla@MAC-KGX5DFMHPX pg_avac % git remote add origin https://github.com/vipulshuklaedb/pg_avac.git
fatal: not a git repository (or any of the parent directories): .git
vipul.shukla@MAC-KGX5DFMHPX pg_avac % pwd
/Users/vipul.shukla/Documents/pg_avac
vipul.shukla@MAC-KGX5DFMHPX pg_avac % cd pg_avac 
vipul.shukla@MAC-KGX5DFMHPX pg_avac % pwd       
/Users/vipul.shukla/Documents/pg_avac/pg_avac
vipul.shukla@MAC-KGX5DFMHPX pg_avac % git remote add origin https://github.com/vipulshuklaedb/pg_avac.git
vipul.shukla@MAC-KGX5DFMHPX pg_avac % git branch -M main
vipul.shukla@MAC-KGX5DFMHPX pg_avac % git push -u origin main
error: src refspec main does not match any
error: failed to push some refs to 'https://github.com/vipulshuklaedb/pg_avac.git'
vipul.shukla@MAC-KGX5DFMHPX pg_avac % git log --oneline
git status
fatal: your current branch 'main' does not have any commits yet
On branch main

No commits yet

Untracked files:
  (use "git add <file>..." to include in what will be committed)
	LICENSE
	Makefile
	README.md
	pg_avac.control
	pg_avac.h

nothing added to commit but untracked files present (use "git add" to track)
vipul.shukla@MAC-KGX5DFMHPX pg_avac % git add .
git commit -m "Initial commit: scaffolding, header, and README"
git push -u origin main
[main (root-commit) 0d5bdab] Initial commit: scaffolding, header, and README
 5 files changed, 443 insertions(+)
 create mode 100644 LICENSE
 create mode 100644 Makefile
 create mode 100644 README.md
 create mode 100644 pg_avac.control
 create mode 100644 pg_avac.h
Username for 'https://github.com': vipulshuklaedb
Password for 'https://vipulshuklaedb@github.com': 
remote: Invalid username or token. Password authentication is not supported for Git operations.
fatal: Authentication failed for 'https://github.com/vipulshuklaedb/pg_avac.git/'
vipul.shukla@MAC-KGX5DFMHPX pg_avac % git add .
git commit -m "Initial commit: scaffolding, header, and README"
git push -u origin main
On branch main
nothing to commit, working tree clean
Username for 'https://github.com': vipulshuklaedb
Password for 'https://vipulshuklaedb@github.com': 
remote: Invalid username or token. Password authentication is not supported for Git operations.
fatal: Authentication failed for 'https://github.com/vipulshuklaedb/pg_avac.git/'
vipul.shukla@MAC-KGX5DFMHPX pg_avac % cat ~/.ssh/agent/s.VvMRfad4MP.agent.uJry6wMaS4 
cat: ai_family not supported: Operation not supported on socket
cat: /Users/vipul.shukla/.ssh/agent/s.VvMRfad4MP.agent.uJry6wMaS4: Invalid argument
vipul.shukla@MAC-KGX5DFMHPX pg_avac % ssh-keygen                
Generating public/private ed25519 key pair.
Enter file in which to save the key (/Users/vipul.shukla/.ssh/id_ed25519): 
Enter passphrase for "/Users/vipul.shukla/.ssh/id_ed25519" (empty for no passphrase): 
Enter same passphrase again: 
Your identification has been saved in /Users/vipul.shukla/.ssh/id_ed25519
Your public key has been saved in /Users/vipul.shukla/.ssh/id_ed25519.pub
The key fingerprint is:
SHA256:drNeMGenxnUCZwZGw5t7i0TWGFxunYUo6JGmjRL0eL8 vipul.shukla@MAC-KGX5DFMHPX
The key's randomart image is:
+--[ED25519 256]--+
|   ..    o +=o...|
|    .o  = ..=+..o|
|    ..o* . ..**..|
|    ..o.o   **.  |
|     .  S =oo.+ .|
|       . o Oo+.o |
|        E ..=o . |
|         . o. .  |
|          .      |
+----[SHA256]-----+
vipul.shukla@MAC-KGX5DFMHPX pg_avac % cat ~/.ssh/id_ed25519
-----BEGIN OPENSSH PRIVATE KEY-----
b3BlbnNzaC1rZXktdjEAAAAABG5vbmUAAAAEbm9uZQAAAAAAAAABAAAAMwAAAAtzc2gtZW
QyNTUxOQAAACCkQ6Zok0RIa5jY4NwL0v23gyTrw3i/vXAXYFR0McqS9QAAAKBNgP5DTYD+
QwAAAAtzc2gtZWQyNTUxOQAAACCkQ6Zok0RIa5jY4NwL0v23gyTrw3i/vXAXYFR0McqS9Q
AAAECP46FsglszxsgS6nz+n1yGDn/0bLyC6vj5gZm1FhuT5aRDpmiTREhrmNjg3AvS/beD
JOvDeL+9cBdgVHQxypL1AAAAG3ZpcHVsLnNodWtsYUBNQUMtS0dYNURGTUhQWAEC
-----END OPENSSH PRIVATE KEY-----
vipul.shukla@MAC-KGX5DFMHPX pg_avac % cat ~/.ssh/id_ed25519.pub
ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAIKRDpmiTREhrmNjg3AvS/beDJOvDeL+9cBdgVHQxypL1 vipul.shukla@MAC-KGX5DFMHPX
vipul.shukla@MAC-KGX5DFMHPX pg_avac % vi ../../
002544\ \(1\).pdf
002544\ \(2\).pdf
002544\ \(3\).pdf
002544.pdf
263710365.pdf
400_7_44277_1763761165_Certification.pdf
88997-\ Backup.rtf
8thSemTranscript.pdf
Aadhaar\ Back.jpg
Aadhar\ Front.jpg
account_close_form.pdf
ACFrOgCP3lZMNkvCLs67PcTEGhEkzWPwgesTfjY66gE5KCgmlwxdQu5VFbtB3ZjPvGjkWfQ6dBmCew4Ir6danbIJF7SVoA5jXGyEUvXkrE3petlWcmdnbWzdqyxKNreHx5SklLD4-ScPOxpqF0WU.pdf
Adding\ new\ replica\ cluster\ to\ OpenShift.docx
alltables.sql
avoid_anti_wraparound_vacuums.sh
AWS\ Keys.txt
BARMAN-SETUP.txt
BayRidgeSignedDoc.pdf
bloat_query.sql
bloat_query.txt
blocks.txt
Book1.xlsx
Book2.xlsx
Bruno.pdf
Car\ Registration.jpg
CNP\ env\ setup.txt
CNP-Gym1.docx
competetive\ strategy.rtf
crash.sh
Delivery\ Note-FZ.docx
Delivery\ Note-Jupiter.docx
Div-Signature.png
Divya\ Fall\ B\ Payment.pdf
DivyaIntCertificate.pdf
DivyaVisa.pdf
Dockerfile
Dockerfile\ 2
drafts.md
Driving\ License\ Vasu\ Tiwari.pdf
EDB\ -\ SHUKLA,\ Vipul\ -\ L-1\ 2025\ -\ Filing\ Scan.pdf
EDB\ -\ SHUKLA,\ Vipul\ -\ L-1\ 2025\ -\ I-129\ Receipt\ Notice.pdf
EDB\ -\ SHUKLA,\ Vipul\ -\ L-1B\ 2025\ -\ I-129\ Approval\ Notice.pdf
EDB\ -\ SHUKLA,\ Vipul\ \(Divya\ Tiwari\)\ -\ L-2\ 2025\ -\ I-539\ Receipt\ Notice.pdf
EDB\ contact.txt
EDB\ contact.zip
EDBPostgresAIDatabaseEssentialsv17Certification_Badge20251125-30-r8u1y6.pdf
efm_setup.sh
efm.properties_template.txt
EFM\ Pod/
EFM\ Pod.zip
efm1.properties
efm2.properties
efm3.properties
ElectricityBill.jpg
Form15G_DivyaTiwari.pdf
FZ25Insurance.pdf
giphy.gif
GitHub/
HCP.pptx
honeylu\'s.docx
How\ to\ learn\ PostgreSQL\ -\ Manager\ Version.txt
I-797B.pdf
i797B.pdf
ID\ Card.pdf
image-20260331-063252.png
IMDBDATA/
IMG_4560.jpg
IMP\ Commands.txt
Ivana\ LT\ E-Bill.pdf
IvanaRegistry.pdf
Jargons.txt
jsonlog.json
KB-Upgrade-With-EFM.txt
KotakIMP.xlsx
KotakLifeInsuranceReceipt.pdf
Lead\ Support\ Engineer.txt
Marksheets/
MBA/
Minor\ version\ upgrade\ -\ rollback.txt
MMR-DB-Upgrade.txt
my\ license.pdf
Node\ Failover\ Timing.docx
Node\ Failover\ Timings.pdf
Odometer.jpg
Passport.pdf
patroni_setup.sh
patroni-setup.txt
PayPath\ Payment\ Service\ Receipt.pdf
Payslips/
pem_generate_certs.sh
Petition.pdf
pg_avac/
PGD5\ Steps.txt
PolicyCopy.pdf
postgres1.yml
postgres2.yml
postgres3.yml
ProgressiveInsurance.jpg
Property\ Tax\ _\ PCMC\ India\ 2023.pdf
Property\ Tax\ _\ PCMC\ India\ bill\ 2023.pdf
Property\ Tax\ _\ PCMC\ India_files/
Property\ Tax\ _\ PCMC\ India.html
Property\ Tax\ _\ PCMC\ India.pdf
Putty\ Keys/
SealyReceipt.jpeg
Siya/
Social\ Media\ Marketing\ Plan.docx
StreamingReplicationSteps.txt
TPAExec.txt
TPAExecSteps.txt
Untitled.png
USLicense-Back.jpg
USLicense-Front.jpg
VAIBHAV\ SHUKLA-CV.pdf
VasuTiwari_resume.pdf
Vip-Signature.png
Vipul_Shukla_EDB.pdf
Vipul_Shukla_US_Offer_Letter.docx.pdf
Vipul-Visa.pdf
VipulIntCertificate.pdf
VipulLicense.pdf
VipulShuklaResume2024.docx
VipulShuklaResume2025.pdf
VipulShuklaResume2026.pdf
VipulVisa.pdf
W-2_Form_2025_Shukla_2026_04_02_13_04_01_-0700_W-2_ESS.pdf
W-2C_Form_2025_Shukla_2026_04_02_13_03_37_-0700_Print_Employee_Copy.pdf
YQA7313588.pdf
YQA7313646.pdf
Zoom/
vipul.shukla@MAC-KGX5DFMHPX pg_avac % vi ../../mygittoken
vipul.shukla@MAC-KGX5DFMHPX pg_avac % git add .                                     
vipul.shukla@MAC-KGX5DFMHPX pg_avac % git commit -m "Initial commit: scaffolding, header, and README" 
On branch main
nothing to commit, working tree clean
vipul.shukla@MAC-KGX5DFMHPX pg_avac % git push -u origin main                               
Username for 'https://github.com': vipulshuklaedb
Password for 'https://vipulshuklaedb@github.com': 
remote: Repository not found.
fatal: repository 'https://github.com/vipulshuklaedb/pg_avac.git/' not found
vipul.shukla@MAC-KGX5DFMHPX pg_avac % git push --help        
vipul.shukla@MAC-KGX5DFMHPX pg_avac % git --help     
usage: git [-v | --version] [-h | --help] [-C <path>] [-c <name>=<value>]
           [--exec-path[=<path>]] [--html-path] [--man-path] [--info-path]
           [-p | --paginate | -P | --no-pager] [--no-replace-objects] [--no-lazy-fetch]
           [--no-optional-locks] [--no-advice] [--bare] [--git-dir=<path>]
           [--work-tree=<path>] [--namespace=<name>] [--config-env=<name>=<envvar>]
           <command> [<args>]

These are common Git commands used in various situations:

start a working area (see also: git help tutorial)
   clone      Clone a repository into a new directory
   init       Create an empty Git repository or reinitialize an existing one

work on the current change (see also: git help everyday)
   add        Add file contents to the index
   mv         Move or rename a file, a directory, or a symlink
   restore    Restore working tree files
   rm         Remove files from the working tree and from the index

examine the history and state (see also: git help revisions)
   bisect     Use binary search to find the commit that introduced a bug
   diff       Show changes between commits, commit and working tree, etc
   grep       Print lines matching a pattern
   log        Show commit logs
   show       Show various types of objects
   status     Show the working tree status

grow, mark and tweak your common history
   backfill   Download missing objects in a partial clone
   branch     List, create, or delete branches
   commit     Record changes to the repository
   merge      Join two or more development histories together
   rebase     Reapply commits on top of another base tip
   reset      Reset current HEAD to the specified state
   switch     Switch branches
   tag        Create, list, delete or verify a tag object signed with GPG

collaborate (see also: git help workflows)
   fetch      Download objects and refs from another repository
   pull       Fetch from and integrate with another repository or a local branch
   push       Update remote refs along with associated objects

'git help -a' and 'git help -g' list available subcommands and some
concept guides. See 'git help <command>' or 'git help <concept>'
to read about a specific subcommand or concept.
See 'git help git' for an overview of the system.
vipul.shukla@MAC-KGX5DFMHPX pg_avac % cd 
vipul.shukla@MAC-KGX5DFMHPX ~ % git config --global vipul.shukla@enterprisedb.com
vipul.shukla@MAC-KGX5DFMHPX ~ % git config --global user.email "vipul.shukla@enterprisedb.com"
vipul.shukla@MAC-KGX5DFMHPX ~ % git config --global user.name "vipulshuklaedb"       
vipul.shukla@MAC-KGX5DFMHPX ~ % curl -H 'Authorization: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'
curl: (2) no URL specified
curl: try 'curl --help' or 'curl --manual' for more information
vipul.shukla@MAC-KGX5DFMHPX ~ % curl -H 'Authorization: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' https://github.com/vipulshuklaedb/pg_avac.git
<html>
<head><title>301 Moved Permanently</title></head>
<body>
<center><h1>301 Moved Permanently</h1></center>
<hr><center>nginx</center>
</body>
</html>
vipul.shukla@MAC-KGX5DFMHPX ~ % git remote set-url origin https://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@github.com/vipulshuklaedb/pg_avac.git
git push -u origin main
fatal: not a git repository (or any of the parent directories): .git
fatal: not a git repository (or any of the parent directories): .git
vipul.shukla@MAC-KGX5DFMHPX ~ % cd -
~/Documents/pg_avac/pg_avac
vipul.shukla@MAC-KGX5DFMHPX pg_avac % git remote set-url origin https://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@github.com/vipulshuklaedb/pg_avac.git
git push -u origin main
remote: Repository not found.
fatal: repository 'https://github.com/vipulshuklaedb/pg_avac.git/' not found
vipul.shukla@MAC-KGX5DFMHPX pg_avac % git remote set-url origin https://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@github.com/enterprisedb/pg_avac.git
git push -u origin main
remote: Write access to repository not granted.
fatal: unable to access 'https://github.com/enterprisedb/pg_avac.git/': The requested URL returned error: 403
vipul.shukla@MAC-KGX5DFMHPX pg_avac % git config --global user.email "vipulrshukla@gmail.com"                                                                                                     
vipul.shukla@MAC-KGX5DFMHPX pg_avac % git config --global user.name "vipulrshukla"                                                                                                             
vipul.shukla@MAC-KGX5DFMHPX pg_avac % git push -u origin main                                                                                                                                  
remote: This repository was archived so it is read-only.
fatal: unable to access 'https://github.com/enterprisedb/pg_avac.git/': The requested URL returned error: 403
vipul.shukla@MAC-KGX5DFMHPX pg_avac % git remote set-url origin https://github.com/vipulrshukla/pg_avac.git
git push -u origin main
Username for 'https://github.com': vipulrshukla
Password for 'https://vipulrshukla@github.com': 
remote: Invalid username or token. Password authentication is not supported for Git operations.
fatal: Authentication failed for 'https://github.com/vipulrshukla/pg_avac.git/'
vipul.shukla@MAC-KGX5DFMHPX pg_avac % git remote set-url origin https://github.com/vipulrshukla/pg_avac.git
git push -u origin main
Username for 'https://github.com': vipulrshukla
Password for 'https://vipulrshukla@github.com': 
remote: Invalid username or token. Password authentication is not supported for Git operations.
fatal: Authentication failed for 'https://github.com/vipulrshukla/pg_avac.git/'
vipul.shukla@MAC-KGX5DFMHPX pg_avac % git remote set-url origin https://github.com/vipulrshukla/pg_avac.git
git push -u origin main
Username for 'https://github.com': vipulrshukla
Password for 'https://vipulrshukla@github.com': 
To https://github.com/vipulrshukla/pg_avac.git
 ! [rejected]        main -> main (fetch first)
error: failed to push some refs to 'https://github.com/vipulrshukla/pg_avac.git'
hint: Updates were rejected because the remote contains work that you do not
hint: have locally. This is usually caused by another repository pushing to
hint: the same ref. If you want to integrate the remote changes, use
hint: 'git pull' before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
vipul.shukla@MAC-KGX5DFMHPX pg_avac % git pull
remote: Enumerating objects: 3, done.
remote: Counting objects: 100% (3/3), done.
remote: Total 3 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
Unpacking objects: 100% (3/3), 852 bytes | 213.00 KiB/s, done.
From https://github.com/vipulrshukla/pg_avac
 * [new branch]      main       -> origin/main
There is no tracking information for the current branch.
Please specify which branch you want to merge with.
See git-pull(1) for details.

    git pull <remote> <branch>

If you wish to set tracking information for this branch you can do so with:

    git branch --set-upstream-to=origin/<branch> main

vipul.shukla@MAC-KGX5DFMHPX pg_avac % git remote set-url origin https://github.com/vipulrshukla/pg_avac.git
git push -u origin main
To https://github.com/vipulrshukla/pg_avac.git
 ! [rejected]        main -> main (non-fast-forward)
error: failed to push some refs to 'https://github.com/vipulrshukla/pg_avac.git'
hint: Updates were rejected because the tip of your current branch is behind
hint: its remote counterpart. If you want to integrate the remote changes,
hint: use 'git pull' before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
vipul.shukla@MAC-KGX5DFMHPX pg_avac % rm ~/.gitconfig

vipul.shukla@MAC-KGX5DFMHPX pg_avac % git remote set-url origin https://github.com/vipulrshukla/pg_avac.git
git push -u origin main
To https://github.com/vipulrshukla/pg_avac.git
 ! [rejected]        main -> main (non-fast-forward)
error: failed to push some refs to 'https://github.com/vipulrshukla/pg_avac.git'
hint: Updates were rejected because the tip of your current branch is behind
hint: its remote counterpart. If you want to integrate the remote changes,
hint: use 'git pull' before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
vipul.shukla@MAC-KGX5DFMHPX pg_avac % rm ~/.gitconfig                                                      

rm: /Users/vipul.shukla/.gitconfig: No such file or directory
vipul.shukla@MAC-KGX5DFMHPX pg_avac % # 1. Create a new repo on github.com (call it pg_avac, leave it empty)

# 2. Then from your local machine:
git clone <this project> pg_avac   # or copy the files
cd pg_avac
git remote add origin https://github.com/vipulrshukla/pg_avac.git
git branch -M main
git push -u origin main
zsh: number expected
zsh: command not found: #
zsh: no such file or directory: this
cd: no such file or directory: pg_avac
error: remote origin already exists.
To https://github.com/vipulrshukla/pg_avac.git
 ! [rejected]        main -> main (non-fast-forward)
error: failed to push some refs to 'https://github.com/vipulrshukla/pg_avac.git'
hint: Updates were rejected because the tip of your current branch is behind
hint: its remote counterpart. If you want to integrate the remote changes,
hint: use 'git pull' before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
vipul.shukla@MAC-KGX5DFMHPX pg_avac % git clone <this project> pg_avac   # or copy the files 
cd pg_avac
git remote add origin https://github.com/vipulrshukla/pg_avac.git
git branch -M main
git push -u origin main
zsh: no such file or directory: this
cd: no such file or directory: pg_avac
error: remote origin already exists.
To https://github.com/vipulrshukla/pg_avac.git
 ! [rejected]        main -> main (non-fast-forward)
error: failed to push some refs to 'https://github.com/vipulrshukla/pg_avac.git'
hint: Updates were rejected because the tip of your current branch is behind
hint: its remote counterpart. If you want to integrate the remote changes,
hint: use 'git pull' before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
vipul.shukla@MAC-KGX5DFMHPX pg_avac % git clone . pg_avac   # or copy the files
cd pg_avac
git remote add origin https://github.com/vipulrshukla/pg_avac.git
git branch -M main
git push -u origin main
fatal: Too many arguments.

usage: git clone [<options>] [--] <repo> [<dir>]

    -v, --[no-]verbose    be more verbose
    -q, --[no-]quiet      be more quiet
    --[no-]progress       force progress reporting
    --[no-]reject-shallow don't clone shallow repository
    -n, --no-checkout     don't create a checkout
    --checkout            opposite of --no-checkout
    --[no-]bare           create a bare repository
    --[no-]mirror         create a mirror repository (implies --bare)
    -l, --[no-]local      to clone from a local repository
    --no-hardlinks        don't use local hardlinks, always copy
    --hardlinks           opposite of --no-hardlinks
    -s, --[no-]shared     setup as shared repository
    --[no-]recurse-submodules[=<pathspec>]
                          initialize submodules in the clone
    --[no-]recursive ...  alias of --recurse-submodules
    -j, --[no-]jobs <n>   number of submodules cloned in parallel
    --[no-]template <template-directory>
                          directory from which templates will be used
    --[no-]reference <repo>
                          reference repository
    --[no-]reference-if-able <repo>
                          reference repository
    --[no-]dissociate     use --reference only while cloning
    -o, --[no-]origin <name>
                          use <name> instead of 'origin' to track upstream
    -b, --[no-]branch <branch>
                          checkout <branch> instead of the remote's HEAD
    --[no-]revision <rev> clone single revision <rev> and check out
    -u, --[no-]upload-pack <path>
                          path to git-upload-pack on the remote
    --[no-]depth <depth>  create a shallow clone of that depth
    --[no-]shallow-since <time>
                          create a shallow clone since a specific time
    --[no-]shallow-exclude <ref>
                          deepen history of shallow clone, excluding ref
    --[no-]single-branch  clone only one branch, HEAD or --branch
    --[no-]tags           clone tags, and make later fetches not to follow them
    --[no-]shallow-submodules
                          any cloned submodules will be shallow
    --[no-]separate-git-dir <gitdir>
                          separate git dir from working tree
    --[no-]ref-format <format>
                          specify the reference format to use
    -c, --[no-]config <key=value>
                          set config inside the new repository
    --[no-]server-option <server-specific>
                          option to transmit
    -4, --ipv4            use IPv4 addresses only
    -6, --ipv6            use IPv6 addresses only
    --[no-]filter <args>  object filtering
    --[no-]also-filter-submodules
                          apply partial clone filters to submodules
    --[no-]remote-submodules
                          any cloned submodules will use their remote-tracking branch
    --[no-]sparse         initialize sparse-checkout file to include only files at root
    --[no-]bundle-uri <uri>
                          a URI for downloading bundles before fetching from origin remote

cd: no such file or directory: pg_avac
error: remote origin already exists.
To https://github.com/vipulrshukla/pg_avac.git
 ! [rejected]        main -> main (non-fast-forward)
error: failed to push some refs to 'https://github.com/vipulrshukla/pg_avac.git'
hint: Updates were rejected because the tip of your current branch is behind
hint: its remote counterpart. If you want to integrate the remote changes,
hint: use 'git pull' before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
vipul.shukla@MAC-KGX5DFMHPX pg_avac % git clone . pg_avac   # or copy the files
cd pg_avac
git remote add origin https://github.com/vipulrshukla/pg_avac.git
vipul.shukla@MAC-KGX5DFMHPX pg_avac % cd pg_avac 
git remote add origin https://github.com/vipulrshukla/pg_avac.git
git branch -M main
git push -u origin main
cd: no such file or directory: pg_avac
error: remote origin already exists.
To https://github.com/vipulrshukla/pg_avac.git
 ! [rejected]        main -> main (non-fast-forward)
error: failed to push some refs to 'https://github.com/vipulrshukla/pg_avac.git'
hint: Updates were rejected because the tip of your current branch is behind
hint: its remote counterpart. If you want to integrate the remote changes,
hint: use 'git pull' before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
vipul.shukla@MAC-KGX5DFMHPX pg_avac % ls -l
total 56
-rw-------@ 1 vipul.shukla  staff   948 May  4  2026 LICENSE
-rw-------@ 1 vipul.shukla  staff   243 May  4  2026 Makefile
-rw-------@ 1 vipul.shukla  staff   188 May  4  2026 pg_avac.control
-rw-------@ 1 vipul.shukla  staff  5707 May  4  2026 pg_avac.h
-rw-------@ 1 vipul.shukla  staff  7265 May  4  2026 README.md
vipul.shukla@MAC-KGX5DFMHPX pg_avac % git remote add origin https://github.com/vipulrshukla/pg_avac.git
error: remote origin already exists.
vipul.shukla@MAC-KGX5DFMHPX pg_avac % git branch -M main
vipul.shukla@MAC-KGX5DFMHPX pg_avac % git push -u origin main
To https://github.com/vipulrshukla/pg_avac.git
 ! [rejected]        main -> main (non-fast-forward)
error: failed to push some refs to 'https://github.com/vipulrshukla/pg_avac.git'
hint: Updates were rejected because the tip of your current branch is behind
hint: its remote counterpart. If you want to integrate the remote changes,
hint: use 'git pull' before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
vipul.shukla@MAC-KGX5DFMHPX pg_avac % git pull origin main --allow-unrelated-histories
From https://github.com/vipulrshukla/pg_avac
 * branch            main       -> FETCH_HEAD
hint: You have divergent branches and need to specify how to reconcile them.
hint: You can do so by running one of the following commands sometime before
hint: your next pull:
hint:
hint:   git config pull.rebase false  # merge
hint:   git config pull.rebase true   # rebase
hint:   git config pull.ff only       # fast-forward only
hint:
hint: You can replace "git config" with "git config --global" to set a default
hint: preference for all repositories. You can also pass --rebase, --no-rebase,
hint: or --ff-only on the command line to override the configured default per
hint: invocation.
fatal: Need to specify how to reconcile divergent branches.
vipul.shukla@MAC-KGX5DFMHPX pg_avac % git push -u origin main                         
To https://github.com/vipulrshukla/pg_avac.git
 ! [rejected]        main -> main (non-fast-forward)
error: failed to push some refs to 'https://github.com/vipulrshukla/pg_avac.git'
hint: Updates were rejected because the tip of your current branch is behind
hint: its remote counterpart. If you want to integrate the remote changes,
hint: use 'git pull' before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
vipul.shukla@MAC-KGX5DFMHPX pg_avac % vi README.md 

# pg_avac

**Automatic vacuum manager for PostgreSQL** — like a Roomba for your database.

`pg_avac` is a PostgreSQL extension that runs as a background worker, continuously monitoring table statistics and firing vacuum jobs intelligently — only when a table actually needs it. It also watches for long-running prepared transactions that can block XID cleanup, and suggests storage parameter changes for tables under heavy load.

---

## How it works

pg_avac wakes on a configurable interval and evaluates every table in your database against three signals:

| Signal | What it measures |
|---|---|
| **Dead tuple ratio** | `n_dead_tup / (n_live_tup + n_dead_tup)` — primary trigger |
| **DML rate** | Inserts + updates + deletes per second since last cycle |
| **Vacuum age** | Seconds since the table was last vacuumed |

From these it assigns each table a strategy: do nothing, `ANALYZE` only, `VACUUM`, `VACUUM ANALYZE`, or flag for manual `VACUUM FULL`. It also separately watches `pg_prepared_xacts` for prepared transactions older than a threshold and fires alerts before they cause bloat.

```
PostgreSQL
└── pg_avac background worker
    ├── Monitor loop  (wakes every N seconds)
    │   ├── Dead tuple ratio check
    │   ├── DML rate check
    │   └── Vacuum age check
    ├── Decision engine  (scores + picks strategy)
    ├── Job executor  (runs VACUUM / ANALYZE)
    ├── Notifier  (pg_notify + log table)
    ├── Prepared TX watcher  (alerts on old XIDs)
    └── Config advisor  (suggests ALTER TABLE params)
```

---

## Requirements

- PostgreSQL 14 or later
- GCC or Clang
- `pg_config` in your `PATH`
- Superuser access to install

---

## Installation

### 1. Clone the repository

```bash
git clone https://github.com/your-org/pg_avac.git
cd pg_avac
```

### 2. Build and install

```bash
make
sudo make install
```

This uses PostgreSQL's PGXS build system. It will automatically find your PostgreSQL installation via `pg_config`. If you have multiple PostgreSQL versions installed, specify which one:
"README.md" 287L, 7265B
