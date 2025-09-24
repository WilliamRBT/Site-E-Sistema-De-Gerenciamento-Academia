import React from 'react';
import { useParams, Link } from 'react-router-dom';
import { CheckCircle } from 'lucide-react';

const planDetails: { [key: string]: { description: string; benefits: string[]; } } = {
  basico: {
    description: 'O plano Básico é ideal para quem busca flexibilidade e acesso essencial à nossa estrutura.',
    benefits: [
      'Acesso 24/7 à área de musculação',
      'Vestiários completos e modernos',
      'Acompanhamento básico inicial com instrutor',
      'Wi-Fi gratuito em todas as áreas',
      'Armários individuais para seus pertences'
    ]
  },
  plus: {
    description: 'O plano Plus oferece uma experiência mais completa, com acesso a aulas e unidades adicionais.',
    benefits: [
      'Todos os benefícios do Plano Básico',
      'Aulas Coletivas Ilimitadas (Spinning, Yoga, Zumba, etc.)',
      'Acesso a todas as unidades da GYM ELITE',
      'Avaliação Física Trimestral com profissional',
      'Descontos exclusivos em parceiros (suplementos, vestuário)'
    ]
  },
  premium: {
    description: 'O plano Premium é a escolha definitiva para quem busca o máximo em suporte e exclusividade.',
    benefits: [
      'Todos os benefícios do Plano Plus',
      'Acompanhamento personalizado com Nutricionista (1 consulta/mês)',
      'Acesso à área de spa e relaxamento (sauna, hidromassagem)',
      'Traga um amigo 4x por mês gratuitamente',
      'Personal Trainer (2 sessões/mês)',
      'Toalhas e amenities de luxo'
    ]
  }
};

const PlanDetailsPage: React.FC = () => {
  const { planName } = useParams<{ planName: string }>();
  const normalizedPlanName = planName ? planName.toLowerCase() : '';
  const planInfo = planDetails[normalizedPlanName];

  if (!planInfo) {
    return (
      <div className="bg-[#121212] text-gray-200 min-h-screen pt-24 flex flex-col items-center justify-center">
        <h2 className="text-4xl md:text-5xl font-black text-white mb-4">Plano Não Encontrado</h2>
        <p className="text-lg text-gray-400 max-w-xl text-center">
          Parece que o plano que você está procurando não existe. Por favor, verifique o link ou volte para a página de planos.
        </p>
        <Link to="/" className="mt-8 inline-block bg-orange-500 text-white font-bold text-base py-3 px-8 rounded-md uppercase tracking-wider hover:bg-orange-600 transition-all duration-300">
          Voltar para Início
        </Link>
      </div>
    );
  }

  return (
    <div className="bg-[#121212] text-gray-200 min-h-screen pt-24"> {/* Added pt-24 for header clearance */}
      <div className="container mx-auto px-6 py-16">
        <div className="text-center mb-16">
          <h2 className="text-4xl md:text-5xl font-black text-white">
            Detalhes do Plano <span className="text-orange-500">{planName?.toUpperCase()}</span>
          </h2>
          <p className="text-lg text-gray-400 mt-4 max-w-3xl mx-auto font-light">
            {planInfo.description}
          </p>
        </div>

        <div className="bg-[#1a1a1a] p-10 rounded-xl border border-gray-800 shadow-lg max-w-3xl mx-auto">
          <h3 className="text-2xl font-bold text-white mb-6">O que você ganha:</h3>
          <ul className="space-y-4 text-gray-300">
            {planInfo.benefits.map((benefit, index) => (
              <li key={index} className="flex items-start">
                <CheckCircle className="text-orange-500 mr-3 flex-shrink-0 mt-1" size={20} />
                <span className="text-lg">{benefit}</span>
              </li>
            ))}
          </ul>
          <div className="mt-10 text-center">
            <p className="text-xl text-gray-300 mb-6">
              Pronto para começar sua jornada com o plano <span className="font-bold text-orange-500">{planName?.toUpperCase()}</span>?
            </p>
            <Link
              to="/contato"
              className="inline-block bg-orange-500 text-white font-bold text-base py-4 px-12 rounded-md uppercase tracking-wider hover:bg-orange-600 transition-all duration-300 transform hover:scale-105 shadow-lg shadow-orange-500/20"
            >
              Entrar em Contato
            </Link>
          </div>
        </div>
      </div>
    </div>
  );
};

export default PlanDetailsPage;