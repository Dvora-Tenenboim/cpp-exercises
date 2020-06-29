#include "dna_sequence.h"
static const char nucleotideArr[]={'A','C','T','G'};
bool isValid(const char nucleotide)
{
	if(nucleotide=='\0')
		return true;
	for(int i=0;i<4;i++)
	{
		if(nucleotide==nucleotideArr[i])
		{
			return true;
		}
	}
	return false;
}
char paire(const char c)
{
	if(c=='A')
		return 'T';
	if(c=='T')
		return 'A';
	if(c=='C')
		return 'G';
	if(c=='G')
		return 'C';
	return '\0';
}
DnaSequence DnaSequence::getSlice(size_t ind1,size_t ind2)const
{
	std::string dnaStr=getAsString();
	return DnaSequence(dnaStr.substr(ind1,ind2));
}
DnaSequence DnaSequence::getPaire()const
{
	std::string dnaStr=getAsString();
	for(size_t i=0;i<m_length/2;i++)
	{
		std::swap(dnaStr[i],dnaStr[m_length-1-i]);
		dnaStr[m_length-1-i]=paire(dnaStr[m_length-1-i]);
		dnaStr[i]=paire(dnaStr[i]);
	}
	if(m_length%2!=0)
		dnaStr[m_length/2]=paire(dnaStr[m_length/2]);
	return DnaSequence(dnaStr);
}
size_t DnaSequence::findSubSequence(const DnaSequence& dnaSeq,size_t pos)const
{
	if(pos>=m_length)
		throw std::out_of_range("out_of_range:  the length of dna sequence is smaller then given pos");
	std::string dnaStr=getAsString();
	return dnaStr.find(dnaSeq.getAsString(),pos);
}
std::vector<size_t> DnaSequence::findAll(const DnaSequence& dnaSeq)const
{
	size_t found=-1;
	std::vector<size_t> foundIndexes;
	std::string myDnaStr=getAsString();
	std::string userDnaStr=dnaSeq.getAsString();
	while(1)
	{
		found=myDnaStr.find(userDnaStr,found+1);
		if(found!=std::string::npos)
			foundIndexes.push_back(found);
		else
			break;
	}
	return foundIndexes;
}
std::vector<DnaSequence> DnaSequence::findConsensusSequences()const
{
	std::vector<size_t> validStarts=findAll("ATG");
	std::vector<DnaSequence> ConsensusSequencesVec;
	size_t validStartsSize=validStarts.size();
	for(size_t i=0;i<validStartsSize;i++)
	{
		for(size_t j=validStarts[i]+3;j<m_length;j+=3)
		{
			if((*this).findSubSequence("TAG",j)==j || (*this).findSubSequence("TAA",j)==j || (*this).findSubSequence("TGA",j)==j)
			{
				ConsensusSequencesVec.push_back(getSlice(validStarts[i],j+2));
			}
		}
	}
	return ConsensusSequencesVec;
}

